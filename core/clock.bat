@echo off
SETLOCAL ENABLEEXTENSIONS
SETLOCAL ENABLEDELAYEDEXPANSION
mode 80,25
:loop
cls
echo.
echo.
type pureScr.rgba     
batbox /g 12 6
echo		   !time:~0,5!
echo.
timeout /t 1 >nul
goto :loop