@echo off
SETLOCAL ENABLEEXTENSIONS
SETLOCAL ENABLEDELAYEDEXPANSION
mode 80,25
:loop
cls
echo.
echo.
type pureScr.rgba     
batbox /g 12 5
echo		         !time:~0,7!
echo.
batbox /k_
if %errorlevel% equ 27 (
    goto:eof
)
timeout /t 1 >nul
goto :loop