@echo off
setlocal enabledelayedexpansion
setlocal enableextensions

:: I386-ASM INSTRUCTION SET ::

:START
set /a firstParam=%1
if %firstParam% == 1 goto :sys_start
if %firstParam% == 2 goto :sys_write
if %firstParam% == 3 goto :final
if %firstParam% == 4 goto :sys_isthis

:final
for /l %%j in (0, 1, 50) do (
    timeout /t 0 >nul
    rem cls
    echo deletando arquivo[%%j_!random!!time:~0,4!]..
)
goto:eof
 
:sys_start
start notepad
goto:eof

:sys_write
set /p "writeInput= "
echo %writeInput% > %random%.%~n0
goto:eof


:sys_isthis
cls
set "scare=Talvez sea el nombre %username% familiar?"
for /l %%k in (1, 1, 45) do (
    timeout /t 0 >nul
    cls
    echo !scare:~0,%%k!
)
goto:eof