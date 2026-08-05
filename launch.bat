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
set "RUN_ONCE=FALSE"

if /i "%~1"=="--build" set "RUN_ONCE=TRUE" & goto BUILD
if /i "%~1"=="--clean" set "RUN_ONCE=TRUE" & goto CLEAN
if /i "%~1"=="--rebuild" set "RUN_ONCE=TRUE" & goto CLEAN_REBUILD

:MENU
cls
echo ============================================================
echo   HPC M7 Build Script  -  Target: %TARGET_BOARD%
echo ============================================================
echo.
echo   1. Build all          (compile + link, no clean)
echo   2. Clean all          (clear %ODIR%, DebugRAM, and generate_RDB3 contents)
echo   3. Clean and rebuild  (clear %ODIR% and DebugRAM, then build)
echo   4. Exit
echo.
echo ------------------------------------------------------------
:MENU_SELECTION
set "MENU_SELECTION="
set /p "MENU_SELECTION=Please select (1-4), then press Enter: "
if "%MENU_SELECTION%"=="4" goto EXIT
if "%MENU_SELECTION%"=="3" goto CLEAN_REBUILD
if "%MENU_SELECTION%"=="2" goto CLEAN
if "%MENU_SELECTION%"=="1" goto BUILD
echo [ERROR] Invalid selection. Enter a number from 1 to 4.
goto MENU_SELECTION

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
"%CYGWIN_BASH%" -c "export PATH=/usr/local/bin:/usr/bin:/bin:$PATH && cd \"$(cygpath -u '%ROOT%')\" && /usr/bin/make build -j%JOBS%"
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
"%CYGWIN_BASH%" -c "export PATH=/usr/local/bin:/usr/bin:/bin:$PATH && cd \"$(cygpath -u '%ROOT%')\" && /usr/bin/make clean clean_debugram && /usr/bin/make build -j%JOBS%"
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
if "%RUN_ONCE%"=="TRUE" exit /b 0
pause
goto MENU

:EXIT
endlocal
exit /b 0