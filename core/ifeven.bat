@echo off
setlocal enableextensions
:start
cls
type pureScr.rgba
echo.
echo. 
echo Even/Odd Calculator
set /p "n=Number: "
set /a "remains=%n% %% 2"
if %remains% equ 0 (
    echo Even
    pause
    goto:start
)
if %remains% NEQ 0 (
    echo Odd
    pause
    goto:start
)
pause>nul
goto:eof