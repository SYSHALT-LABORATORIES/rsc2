@echo off
setlocal enableextensions
setlocal enabledelayedexpansion
mode 80,25
title editor

:EDIT
type pureScr.rgba
echo.
echo Bienvenido al editor de texto.
set /p "name=Cual sera el nombre del archivo?: "
set /p "_Fext=Extension ^(sin punto)^:  "
set /p "getLines=Cuantas lineas quieres escribir?: "
for /l %%i in (0, 1, %getLines%) do (
    set /p "Lines[%%i]=Linea %%i/%getlines%: "
)
goto:MENU

:MENU
cls
echo Para guardar el archivo, presiona S.
echo Para salir, presiona E ^(podes perder tu trabajo!)^.
choice /c se
if %errorlevel% equ 1 (
	goto:SAVE
)
if %errorlevel% equ 2 (
	goto:eof
)

:SAVE
echo Generando..
for /l %%k in (0, 1, %getLines%) do (
	set "_Data=!Lines[%%k]! "
	echo !_Data! >> %name%.%_Fext%
)
ping -n 2 localhost >nul
echo Hecho!
pause>nul
goto:eof