@echo off
setlocal enableextensions
setlocal enabledelayedexpansion

:MAIN
call syscall 8 purescr.rgba
echo.
echo.
for /f "tokens=* delims=" %%x in (username.dat) do (set "usern[%%x]=%%x")
for /f "tokens=* delims=" %%y in (password.dat) do (set "passw[%%y]=%%y")

call input userioname "Username: "
call input useriopwd "Password: "
goto:CHECK

:CHECK
if %usern% NEQ %userioname% (echo Wrong username && goto:MAIN)
if %passw% NEQ %useriopwd% (echo Wrong password && goto:MAIN)
goto:eof
 
