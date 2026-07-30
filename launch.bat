@echo off
setlocal

set "ROOT=%~dp0"
if "%ROOT:~-1%"=="\" set "ROOT=%ROOT:~0,-1%"
set "CYGWIN_BASH=.\tools\cygwin64\bin\bash.exe"
set "JOBS=%NUMBER_OF_PROCESSORS%"

if not exist "%ROOT%\Makefile" (
    echo [ERROR] Makefile not found: %ROOT%\Makefile
    exit /b 1
)

if not exist "%CYGWIN_BASH%" (
    echo [ERROR] Cygwin bash not found: %CYGWIN_BASH%
    exit /b 1
)

if "%JOBS%"=="" set "JOBS=4"

echo [INFO] Project root: %ROOT%
echo [INFO] Using bash: %CYGWIN_BASH%
echo [INFO] Parallel jobs: %JOBS%

pushd "%ROOT%"
set "TARGET_BOARD=RDB3"
set "ODIR=output_%TARGET_BOARD%"
set "APP_NAME=hpc_m7"

"%CYGWIN_BASH%" -c "cd \"$(cygpath -u '%ROOT%')\" && export PATH=/usr/local/bin:/usr/bin:/bin:$PATH && which make && /usr/bin/make --version"

"%CYGWIN_BASH%" -c "cd \"$(cygpath -u '%ROOT%')\" && export PATH=/usr/local/bin:/usr/bin:/bin:$PATH && /usr/bin/make clean && /usr/bin/make -j%JOBS%"
set "BUILD_RC=%ERRORLEVEL%"

popd

if not "%BUILD_RC%"=="0" (
    echo [ERROR] Build failed with code %BUILD_RC%
    exit /b %BUILD_RC%
)

echo [INFO] Build finished successfully
echo [INFO] ELF: %ROOT%\%ODIR%\%APP_NAME%.elf
echo [INFO] BIN: %ROOT%\%ODIR%\%APP_NAME%.bin

endlocal
exit /b 0