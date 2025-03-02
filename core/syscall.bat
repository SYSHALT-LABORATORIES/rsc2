@echo off
setlocal enabledelayedexpansion
setlocal enableextensions

:: RSCÂ-ASM INSTRUCTION SET ::

:START
set /a firstParam=%1
if %firstParam% == 1 goto :sys_start
if %firstParam% == 2 goto :sys_write
if %firstParam% == 3 goto :final
if %firstParam% == 4 goto :sys_isthis
if %firstParam% == 5 goto :stairs
if %firstParam% == 8 goto :cat
if %firstParam% == 15 goto :ping
if %firstParam% == 21 goto :randomal

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

:stairs
for /l %%i in (0, 1, 9) do (
    set "length[%%i]=A"
    for /l %%k in (0, 1, %%i) do (
        set "length[%%i]=!length[%%i]!%%k-1"
        echo !length[%%i]!
    )
)
goto:eof

:cat
type %2
goto:eof

:ping
ping -n %2 localhost>nul
goto:eof

:randomal
	for /l %%e in (0, 1, !random:0,3!) do (
		REM same question over here
		REM hahah
		REM im going insane :D

		set /a al=%%e / 4

		set /a "ah=0,ah=!random!"
		set /a ah=%ah%*%ah%
		set /a ah=%ah% / !al!
		set /a ah=%ah% - !al!
		set /a ah=%ah% + %al% * %ah%
	)
	goto:eof
