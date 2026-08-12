# Axivion analysis helper invoked by the project launch script.
[CmdletBinding()]
param(
    [Parameter(Mandatory = $true)]
    [string]$ProjectRoot,

    [Parameter(Mandatory = $true)]
    [string]$InputPath,

    [string]$AxivionHome = 'C:\LegacyApp\AxivionSuite\7.9.4',

    [int]$Jobs = 4
)

$ErrorActionPreference = 'Stop'

function Write-Log {
    param([string]$Message)
    Write-Host $Message
    Add-Content -LiteralPath $script:LogFile -Value $Message -Encoding UTF8
}

function Invoke-NativeLogged {
    param(
        [string]$Step,
        [string]$FilePath,
        [string[]]$ArgumentList
    )

    Write-Log ""
    Write-Log "[STEP] $Step"
    # Windows PowerShell can turn native stderr into a terminating
    # NativeCommandError when the script-wide preference is Stop. Capture the
    # complete native output and exit code instead, so the log explains the
    # actual Axivion failure.
    $previousErrorActionPreference = $ErrorActionPreference
    try {
        $ErrorActionPreference = 'Continue'
        $output = & $FilePath @ArgumentList 2>&1
        $rc = $LASTEXITCODE
    }
    finally {
        $ErrorActionPreference = $previousErrorActionPreference
    }
    foreach ($line in $output) {
        $text = [string]$line
        Write-Host $text
        Add-Content -LiteralPath $script:LogFile -Value $text -Encoding UTF8
    }
    Write-Log "[STEP] Exit code: $rc"
    return $rc
}

function Convert-ToAbsolutePath {
    param([string]$PathValue, [string]$BasePath)

    $candidate = $PathValue.Trim().Trim('"')
    if (-not [System.IO.Path]::IsPathRooted($candidate)) {
        $candidate = Join-Path $BasePath $candidate
    }
    return [System.IO.Path]::GetFullPath($candidate)
}

function Convert-ToCygwinPath {
    param([string]$WindowsPath)

    $full = [System.IO.Path]::GetFullPath($WindowsPath)
    if ($full -match '^([A-Za-z]):\\(.*)$') {
        return '/cygdrive/' + $Matches[1].ToLowerInvariant() + '/' + $Matches[2].Replace('\', '/')
    }
    return $full.Replace('\', '/')
}

function Resolve-SourcePath {
    param([string]$SourcePath, [string]$BasePath)

    $candidate = $SourcePath.Trim('"').Replace('/', '\')
    if (-not [System.IO.Path]::IsPathRooted($candidate)) {
        $candidate = Join-Path $BasePath $candidate
    }
    return [System.IO.Path]::GetFullPath($candidate)
}

$ProjectRoot = [System.IO.Path]::GetFullPath($ProjectRoot.Trim().Trim('"'))
$AxivionHome = [System.IO.Path]::GetFullPath($AxivionHome.Trim().Trim('"'))
if ($Jobs -lt 1) { $Jobs = 1 }

$logRoot = Join-Path $ProjectRoot 'build_logs'
$axivionRoot = Join-Path $logRoot 'axivion'
$timestamp = Get-Date -Format 'yyyyMMdd_HHmmss'
$runDir = Join-Path $axivionRoot "run_$timestamp"
$configDir = Join-Path $runDir 'config'
$objectDir = Join-Path $runDir 'objects'
$script:LogFile = Join-Path $logRoot "axivion_$timestamp.log"
$latestLog = Join-Path $logRoot 'axivion_latest.log'
$rawMakeLog = Join-Path $runDir 'make_dry_run.log'
$compileCommandsFile = Join-Path $runDir 'compile_commands.json'
$irFile = Join-Path $runDir 'selected_sources.ir'
$axvFile = Join-Path $logRoot "axivion_$timestamp.axv"
$csvFile = Join-Path $logRoot "axivion_$timestamp.csv"
$latestAxv = Join-Path $logRoot 'axivion_latest.axv'
$latestCsv = Join-Path $logRoot 'axivion_latest.csv'

New-Item -ItemType Directory -Force -Path $logRoot, $axivionRoot, $runDir, $configDir, $objectDir | Out-Null
Set-Content -LiteralPath $script:LogFile -Value '' -Encoding UTF8

$exitCode = 1
try {
    Write-Log '============================================================'
    Write-Log ' Axivion Static Analysis'
    Write-Log '============================================================'
    Write-Log "[INFO] Project:       $ProjectRoot"
    Write-Log "[INFO] Input:         $InputPath"
    Write-Log "[INFO] Axivion:       $AxivionHome"
    Write-Log "[INFO] Parallel jobs: $Jobs"
    Write-Log "[INFO] Run directory: $runDir"

    $requiredTools = @(
        (Join-Path $AxivionHome 'bin\gccsetup.exe'),
        (Join-Path $AxivionHome 'bin\build_compile_commands.exe'),
        (Join-Path $AxivionHome 'bin\axivion_analysis.exe')
    )
    foreach ($tool in $requiredTools) {
        if (-not (Test-Path -LiteralPath $tool -PathType Leaf)) {
            throw "Required Axivion tool not found: $tool"
        }
    }

    $cygwinBash = 'D:\Tools\cygwin64\bin\bash.exe'
    if (-not (Test-Path -LiteralPath $cygwinBash -PathType Leaf)) {
        throw "Cygwin bash not found: $cygwinBash"
    }
    if (-not (Test-Path -LiteralPath (Join-Path $ProjectRoot 'Makefile') -PathType Leaf)) {
        throw "Makefile not found under project root: $ProjectRoot"
    }

    $selectedPath = Convert-ToAbsolutePath -PathValue $InputPath -BasePath $ProjectRoot
    if (-not (Test-Path -LiteralPath $selectedPath)) {
        throw "Input path does not exist: $selectedPath"
    }

    if (Test-Path -LiteralPath $selectedPath -PathType Leaf) {
        if ([System.IO.Path]::GetExtension($selectedPath) -ine '.c') {
            throw "Only a .c file can be selected: $selectedPath"
        }
        $selectedFiles = @((Get-Item -LiteralPath $selectedPath).FullName)
        $selectionType = 'file'
    }
    else {
        $selectedFiles = @(
            Get-ChildItem -LiteralPath $selectedPath -Recurse -File -Filter '*.c' |
                Sort-Object FullName |
                ForEach-Object { $_.FullName }
        )
        $selectionType = 'directory'
    }

    if ($selectedFiles.Count -eq 0) {
        throw "No .c files found under: $selectedPath"
    }
    Write-Log "[INFO] Selection type: $selectionType"
    Write-Log "[INFO] C files found:  $($selectedFiles.Count)"

    # Ask Make for the exact compiler commands without modifying build outputs.
    $rootCygwin = Convert-ToCygwinPath -WindowsPath $ProjectRoot
    $bashCommand = "export PATH=/usr/local/bin:/usr/bin:/bin:`$PATH; cd '$rootCygwin' || exit `$?; /usr/bin/make --always-make --dry-run build"
    Write-Log ''
    Write-Log '[STEP] Extract compiler commands from Makefile (dry run)'
    $makeOutput = @(& $cygwinBash -lc $bashCommand 2>&1)
    $makeRc = $LASTEXITCODE
    $makeOutput | Set-Content -LiteralPath $rawMakeLog -Encoding UTF8
    Write-Log "[INFO] Make dry-run exit code: $makeRc"
    Write-Log "[INFO] Make dry-run output:    $rawMakeLog"
    if ($makeRc -ne 0) {
        foreach ($line in ($makeOutput | Select-Object -Last 30)) { Write-Log ([string]$line) }
        throw "Unable to extract compiler commands from Makefile (exit code $makeRc)."
    }

    $compileBySource = @{}
    $templateCommand = $null
    $templateSourcePattern = '(?i)(?:"(?<sourceQuoted>[^"]+\.c)"|(?<sourceBare>\S+\.c))\s+-o\s+(?:"(?<outputQuoted>[^"]+)"|(?<outputBare>\S+))\s*$'

    foreach ($rawLine in $makeOutput) {
        $line = [string]$rawLine
        if (($line -notmatch '(?i)arm-none-eabi-gcc(?:\.exe)?\s') -or ($line -notmatch '\s-c\s')) {
            continue
        }
        $match = [regex]::Match($line, $templateSourcePattern)
        if (-not $match.Success) { continue }

        $sourceToken = if ($match.Groups['sourceQuoted'].Success) {
            $match.Groups['sourceQuoted'].Value
        } else {
            $match.Groups['sourceBare'].Value
        }
        $sourceFullPath = Resolve-SourcePath -SourcePath $sourceToken -BasePath $ProjectRoot
        $compileBySource[$sourceFullPath.ToLowerInvariant()] = $line
        if ($null -eq $templateCommand) { $templateCommand = $line }
    }

    if ($compileBySource.Count -eq 0 -or $null -eq $templateCommand) {
        throw 'No ARM GCC C compilation commands were found in the Makefile dry run.'
    }
    Write-Log "[INFO] Makefile C units: $($compileBySource.Count)"

    $compileEntries = New-Object System.Collections.Generic.List[object]
    $fallbackCount = 0
    $index = 0
    foreach ($sourceFile in $selectedFiles) {
        $index++
        $sourceKey = ([System.IO.Path]::GetFullPath($sourceFile)).ToLowerInvariant()
        if ($compileBySource.ContainsKey($sourceKey)) {
            $command = [string]$compileBySource[$sourceKey]
        }
        else {
            # Files outside the normal build still use the project's global ARM GCC
            # flags and include paths. Axivion will report any missing local setup.
            $fallbackCount++
            $command = [regex]::Replace(
                $templateCommand,
                $templateSourcePattern,
                { param($m) '"' + $sourceFile.Replace('\', '/') + '" -o fallback.o' },
                1
            )
        }

        $baseName = [System.IO.Path]::GetFileNameWithoutExtension($sourceFile)
        $safeBaseName = [regex]::Replace($baseName, '[^A-Za-z0-9_.-]', '_')
        $objectPath = Join-Path $objectDir ('{0:D5}_{1}.o' -f $index, $safeBaseName)
        $objectForCommand = $objectPath.Replace('\', '/')
        $command = [regex]::Replace(
            $command,
            '(?i)(\s-o\s+)(?:"[^"]+"|\S+)\s*$',
            { param($m) $m.Groups[1].Value + '"' + $objectForCommand + '"' },
            1
        )

        $compileEntries.Add([ordered]@{
            directory = $ProjectRoot
            command   = $command
            file      = [System.IO.Path]::GetFullPath($sourceFile)
            output    = $objectPath
        })
    }

    if ($fallbackCount -gt 0) {
        Write-Log "[WARN] $fallbackCount selected file(s) are not normal Makefile units; project-global flags will be used."
    }
    # Python's json.load(encoding='utf-8') rejects the BOM emitted by Windows
    # PowerShell's Set-Content -Encoding UTF8. Also keep a JSON array when only
    # one C file is selected.
    $compileCommandsJson = ConvertTo-Json -InputObject @($compileEntries.ToArray()) -Depth 5
    $utf8WithoutBom = New-Object System.Text.UTF8Encoding -ArgumentList $false
    [System.IO.File]::WriteAllText(
        $compileCommandsFile,
        $compileCommandsJson,
        $utf8WithoutBom
    )
    Write-Log "[INFO] Compilation database: $compileCommandsFile"

    $compilerMatch = [regex]::Match($templateCommand, '^\s*(?:"(?<quoted>[^"]*arm-none-eabi-gcc(?:\.exe)?)"|(?<bare>\S*arm-none-eabi-gcc(?:\.exe)?))')
    if (-not $compilerMatch.Success) {
        throw 'Unable to determine ARM GCC executable from Makefile command.'
    }
    $gccExecutable = if ($compilerMatch.Groups['quoted'].Success) {
        $compilerMatch.Groups['quoted'].Value
    } else {
        $compilerMatch.Groups['bare'].Value
    }
    $gccExecutable = Resolve-SourcePath -SourcePath $gccExecutable -BasePath $ProjectRoot
    if (-not (Test-Path -LiteralPath $gccExecutable -PathType Leaf)) {
        throw "ARM GCC executable not found: $gccExecutable"
    }

    $profileSwitches = New-Object System.Collections.Generic.List[string]
    foreach ($pattern in @('--sysroot=(?:"[^"]+"|\S+)', '-mcpu=\S+', '-mthumb', '-mfpu=\S+', '-mfloat-abi=\S+', '-mlittle-endian')) {
        $m = [regex]::Match($templateCommand, '(?<!\S)' + $pattern + '(?=\s|$)')
        if ($m.Success -and -not $profileSwitches.Contains($m.Value)) {
            $profileSwitches.Add($m.Value)
        }
    }
    $gccSetupCommand = '"' + $gccExecutable + '"'
    if ($profileSwitches.Count -gt 0) {
        $gccSetupCommand += ' ' + ($profileSwitches -join ' ')
    }

    $axivionBin = Join-Path $AxivionHome 'bin'
    $env:Path = $axivionBin + ';' + (Split-Path -Parent $gccExecutable) + ';' + $env:Path
    $env:CAFECC_BASEPATH = $ProjectRoot

    $gccSetup = Join-Path $axivionBin 'gccsetup.exe'
    $rc = Invoke-NativeLogged -Step 'Create Axivion compiler profile for ARM GCC' -FilePath $gccSetup -ArgumentList @(
        '--cc', $gccSetupCommand,
        '--cxx', 'None',
        '--config', $configDir
    )
    if ($rc -ne 0) { throw "Axivion gccsetup failed with exit code $rc." }

    $env:BAUHAUS_CONFIG = $configDir
    Write-Log "[INFO] BAUHAUS_CONFIG: $configDir"

    $buildCompileCommands = Join-Path $axivionBin 'build_compile_commands.exe'
    $rc = Invoke-NativeLogged -Step 'Build Axivion IR for selected C sources' -FilePath $buildCompileCommands -ArgumentList @(
        '-B', $ProjectRoot,
        '-j', [string]$Jobs,
        '--output_filename', $irFile,
        $compileCommandsFile
    )
    if ($rc -ne 0) { throw "Axivion IR build failed with exit code $rc." }
    if (-not (Test-Path -LiteralPath $irFile -PathType Leaf)) {
        throw "Axivion IR file was not generated: $irFile"
    }

    $axivionAnalysis = Join-Path $axivionBin 'axivion_analysis.exe'
    $rc = Invoke-NativeLogged -Step 'Run Axivion unit, style, and analysis-control checks' -FilePath $axivionAnalysis -ArgumentList @(
        '--unit',
        '--output', $axvFile,
        '--output_csv_sv', $csvFile,
        '--omit_disabled',
        '--limit_to', 'Stylechecks',
        '--limit_to', 'AnalysisControl',
        '--ir', $irFile
    )
    if ($rc -ne 0) { throw "Axivion analysis failed with exit code $rc." }
    if (-not (Test-Path -LiteralPath $axvFile -PathType Leaf)) {
        throw "Axivion result file was not generated: $axvFile"
    }
    if (-not (Test-Path -LiteralPath $csvFile -PathType Leaf)) {
        throw "Axivion CSV report was not generated: $csvFile"
    }

    Copy-Item -LiteralPath $axvFile -Destination $latestAxv -Force
    Copy-Item -LiteralPath $csvFile -Destination $latestCsv -Force

    Write-Log ''
    Write-Log '[INFO] Axivion analysis finished successfully.'
    Write-Log "[INFO] Analyzed C files: $($selectedFiles.Count)"
    Write-Log "[INFO] Text log:        $script:LogFile"
    Write-Log "[INFO] CSV report:      $csvFile"
    Write-Log "[INFO] AXV result:      $axvFile"
    Write-Log "[INFO] Latest CSV:      $latestCsv"
    Write-Log "[INFO] Latest AXV:      $latestAxv"
    Write-Log "[INFO] Intermediate IR: $irFile"
    $exitCode = 0
}
catch {
    Write-Log ''
    Write-Log "[ERROR] $($_.Exception.Message)"
    Write-Log "[ERROR] Axivion analysis failed. See: $script:LogFile"
    $exitCode = 1
}
finally {
    if (Test-Path -LiteralPath $script:LogFile -PathType Leaf) {
        Copy-Item -LiteralPath $script:LogFile -Destination $latestLog -Force
    }
}

exit $exitCode
