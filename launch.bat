@echo off
setlocal

set "ROOT=%~dp0"
if "%ROOT:~-1%"=="\" set "ROOT=%ROOT:~0,-1%"
set "CYGWIN_BASH=D:\Tools\cygwin64\bin\bash.exe"
set "JOBS=%NUMBER_OF_PROCESSORS%"

if not exist "%ROOT%\Makefile" (
    echo [ERROR] Makefile not found: %ROOT%\Makefile
    pause
    exit /b 1
)

if not exist "%CYGWIN_BASH%" (
    echo [ERROR] Cygwin bash not found: %CYGWIN_BASH%
    pause
    exit /b 1
)

if "%JOBS%"=="" set "JOBS=4"

set "TARGET_BOARD=RDB3"
set "ODIR=output_%TARGET_BOARD%"
set "APP_NAME=hpc_m7"
set "LOG_DIR=build_logs"
set "LATEST_LOG=%LOG_DIR%\build_latest.log"
set "RUN_ONCE=FALSE"

if /i "%~1"=="--build" (
    set "RUN_ONCE=TRUE"
    goto BUILD
)
if /i "%~1"=="--clean" (
    set "RUN_ONCE=TRUE"
    goto CLEAN
)
if /i "%~1"=="--rebuild" (
    set "RUN_ONCE=TRUE"
    goto CLEAN_REBUILD
)
if /i "%~1"=="--axivion" (
    set "RUN_ONCE=TRUE"
    set "AXIVION_INPUT=%~2"
    goto AXIVION
)

:MENU
cls
echo ============================================================
echo   HPC M7 Build Script  -  Target: %TARGET_BOARD%
echo ============================================================
echo.
echo   1. Build all          (compile + link, no clean)
echo   2. Clean all          (clear %ODIR%, DebugRAM, and generate_RDB3 contents)
echo   3. Clean and rebuild  (clear %ODIR% and DebugRAM, then build)
echo   4. Axivion analysis   (select a .c file or a directory)
echo   5. Exit
echo.
echo ------------------------------------------------------------
:MENU_SELECTION
set "MENU_SELECTION="
set /p "MENU_SELECTION=Please select (1-5), then press Enter: "
if "%MENU_SELECTION%"=="5" goto EXIT
if "%MENU_SELECTION%"=="4" goto AXIVION
if "%MENU_SELECTION%"=="3" goto CLEAN_REBUILD
if "%MENU_SELECTION%"=="2" goto CLEAN
if "%MENU_SELECTION%"=="1" goto BUILD
echo [ERROR] Invalid selection. Enter a number from 1 to 5.
goto MENU_SELECTION

:AXIVION
echo.
if not defined AXIVION_INPUT (
    echo Enter a .c file path or a directory path.
    echo A directory selection recursively analyzes all .c files below it.
    set /p "AXIVION_INPUT=Axivion input path: "
)
if not defined AXIVION_INPUT (
    echo [ERROR] Axivion input path cannot be empty.
    if "%RUN_ONCE%"=="TRUE" exit /b 1
    pause
    goto MENU
)
if not "%RUN_ONCE%"=="TRUE" (
    echo.
    set "AXIVION_CONFIRM="
    set /p "AXIVION_CONFIRM=Path accepted. Press Enter to start Axivion analysis: "
)
echo.
echo [INFO] Starting Axivion analysis ...
powershell.exe -NoProfile -ExecutionPolicy Bypass -File "%ROOT%\tools\scripts\run_axivion.ps1" -ProjectRoot "%ROOT%" -InputPath "%AXIVION_INPUT%" -Jobs %JOBS%
set "AXIVION_RC=%ERRORLEVEL%"
echo.
if not "%AXIVION_RC%"=="0" (
    echo [ERROR] Axivion analysis failed with code %AXIVION_RC%
) else (
    echo [INFO] Axivion analysis finished successfully
    echo [INFO] Latest Axivion CSV: %ROOT%\%LOG_DIR%\axivion_latest.csv
    echo [INFO] Latest Axivion AXV: %ROOT%\%LOG_DIR%\axivion_latest.axv
)
echo [INFO] Latest Axivion log: %ROOT%\%LOG_DIR%\axivion_latest.log
set "AXIVION_INPUT="
if "%RUN_ONCE%"=="TRUE" exit /b %AXIVION_RC%
pause
goto MENU

:CLEAN
echo.
echo [INFO] Cleaning %ODIR% and DebugRAM ...
pushd "%ROOT%"
"%CYGWIN_BASH%" -c "export PATH=/usr/local/bin:/usr/bin:/bin:$PATH && cd \"$(cygpath -u '%ROOT%')\" && /usr/bin/make clean_all"
set "RC=%ERRORLEVEL%"
popd
if not "%RC%"=="0" (
    echo [ERROR] Clean failed with code %RC%
) else (
    echo [INFO] Clean finished successfully
)
if "%RUN_ONCE%"=="TRUE" exit /b %RC%
pause
goto MENU

:BUILD
echo.
echo [INFO] Project root: %ROOT%
echo [INFO] Using bash:   %CYGWIN_BASH%
echo [INFO] Parallel jobs: %JOBS%
echo [INFO] Output dir:   %ODIR%
echo.
pushd "%ROOT%"
"%CYGWIN_BASH%" -c "export PATH=/usr/local/bin:/usr/bin:/bin:$PATH; cd \"$(cygpath -u '%ROOT%')\" || exit $?; mkdir -p '%LOG_DIR%' || exit $?; LOG_FILE=%LOG_DIR%/build_$(date +%%Y%%m%%d_%%H%%M%%S).log; set -o pipefail; /usr/bin/make build -j%JOBS% 2>&1 | tee \"$LOG_FILE\"; RC=${PIPESTATUS[0]}; cp \"$LOG_FILE\" '%LATEST_LOG%'; exit $RC"
set "BUILD_RC=%ERRORLEVEL%"
popd
goto CHECK_RESULT

:CLEAN_REBUILD
echo.
echo [INFO] Project root: %ROOT%
echo [INFO] Using bash:   %CYGWIN_BASH%
echo [INFO] Parallel jobs: %JOBS%
echo [INFO] Output dir:   %ODIR%
echo.
pushd "%ROOT%"
"%CYGWIN_BASH%" -c "export PATH=/usr/local/bin:/usr/bin:/bin:$PATH; cd \"$(cygpath -u '%ROOT%')\" || exit $?; /usr/bin/make clean clean_debugram || exit $?; mkdir -p '%LOG_DIR%' || exit $?; LOG_FILE=%LOG_DIR%/build_$(date +%%Y%%m%%d_%%H%%M%%S).log; set -o pipefail; /usr/bin/make build -j%JOBS% 2>&1 | tee \"$LOG_FILE\"; RC=${PIPESTATUS[0]}; cp \"$LOG_FILE\" '%LATEST_LOG%'; exit $RC"
set "BUILD_RC=%ERRORLEVEL%"
popd
goto CHECK_RESULT

:CHECK_RESULT
echo.
if not "%BUILD_RC%"=="0" (
    echo [ERROR] Build failed with code %BUILD_RC%
    if "%RUN_ONCE%"=="TRUE" exit /b %BUILD_RC%
    pause
    goto MENU
)
echo [INFO] Build finished successfully
echo [INFO] ELF: %ROOT%\%ODIR%\%APP_NAME%.elf
echo [INFO] BIN: %ROOT%\%ODIR%\%APP_NAME%.bin
echo [INFO] MAP: %ROOT%\%ODIR%\%APP_NAME%.map
echo [INFO] LOG: %ROOT%\%LATEST_LOG%
if "%RUN_ONCE%"=="TRUE" exit /b 0
pause
goto MENU

:EXIT
endlocal
exit /b 0
