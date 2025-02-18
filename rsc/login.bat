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
for /f "tokens=* delims=" %%z in (%usern%) do (set "usernConc=usern[%%z]")
for /f "tokens=* delims=" %%w in (%passw%) do (set "passwConc=passw[%%w]")

if %usernConc% NEQ %userioname% (echo Wrong username && goto:MAIN)
if %passwConc% NEQ %useriopwd% (echo Wrong password && goto:MAIN)

if %usernConc% EQU %userioname% (echo )
if %passwConc% EQU %useriopwd% (echo Password correct!)

ping -n localhost 2>nul
cls
call mainOS.bat
goto:eof
 
