@echo off
setlocal enabledelayedexpansion
setlocal enableextensions
mode 80,25
color 0a
:calc
cls
type sqr.rgba
choice /c MDASE /m "Mul Div Add Sub Exit "
if %errorlevel% equ 1 goto mul
if %errorlevel% equ 2 goto div
if %errorlevel% equ 3 goto add
if %errorlevel% equ 4 goto sub
if %errorlevel% equ 5 goto:eof

:mul
set /p "n1=Inserta Numero 1: "
set /p "n2=Inserta Numero 2: "
set /a _Result=n1 * n2
echo Resultado: %_Result% 
pause>nul
goto:calc

:div
set /p "n1=Inserta Numero 1: "
set /p "n2=Inserta Numero 2: "
set /a _Result=n1 / n2
echo Resultado: %_Result% 
pause>nul
goto:calc

:add
set /p "n1=Inserta Numero 1: "
set /p "n2=Inserta Numero 2: "
set /a _Result=n1 + n2
echo Resultado: %_Result%
pause>nul
goto:calc

:sub
set /p "n1=Inserta Numero 1: "
set /p "n2=Inserta Numero 2: "
set /a _Result=n1 - n2
echo Resultado: %_Result% 
pause>nul
goto:calc