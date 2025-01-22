@echo off
setlocal enableextensions
setlocal enabledelayedexpansion
mode 80,25
title rscý
REM cd c:\
pushd core
:OSMENU
cls
color 1f
type mainscr.rgba
echo. 
batbox /d "			"
batbox /c 0x4E && batbox /d "1 - Calculadora"
echo.
echo.
batbox /c 0x1F
batbox /d "			" && batbox /c 0x4E
batbox /d "2 - Pacman"
echo.
echo.
batbox /c 0x1f
batbox /d "			" 
batbox /c 0x4E && batbox /d "3 - Exit"
batbox /c 0x1f
echo.
echo.
batbox /d "			" && batbox /c 0x4E
batbox /d "4 - Editor de texto"
batbox /c 0x1f
echo.
echo.
set /p "_0=Elija una tarea (numeros):   "
if %_0% == 1 (
	pushd core
	call calc.bat
	cls
	color 1f
	echo QUALQUIER TECLA PARA VOLVER
	pause >nul
	goto:OSMENU
)

if %_0% == 2 (
	call pacman.bat
	cls
	color 1f
	echo QUALQUIER TECLA PARA VOLVER
	pause >nul
	goto:OSMENU
)

if %_0% == 3 (
	goto:eof
)

if %_0% == 4 (
	rem shutdown /l
	call dialogue.bat
	cls
	color 1f
	echo QUALQUIER TECLA PARA VOLVER
	pause >nul
	goto:OSMENU
)

if %_0% gtr 4 (
	batbox /c 0x14 && batbox /d "ERROR: Entrada invalida"
	type bel.snd
	pause>nul
	goto:OSMENU
)
pause>nul
goto:eof