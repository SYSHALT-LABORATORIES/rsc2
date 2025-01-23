@echo off
setlocal enableextensions
setlocal enabledelayedexpansion

pushd core
echo ========= Triangle Area Calculator =========
echo.

input base Base
input height Height
mul %height% %base%

echo %errlevelAdd%
pause>nul