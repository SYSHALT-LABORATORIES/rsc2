@echo off
setlocal enableextensions
setlocal enabledelayedexpansion
call i32 pi 3.14159265358979323846  REM ; set /a "pi=3.1415926535897932384"
call i32 a %pi% %% 2 * %pi%         REM ; set /a "a=%pi% %% 2 * %pi%"
if %a% lss 0 (
    call i32 a 2 * %pi% - a         REM ; set /a "a=2*%pi%-%a%"
)

call i32 sign 1                     REM ; set /a "sign=1"
if %a% gtr %pi% (
    call i32 a %a% - %pi%           REM ; set /a "a=%a%-%pi%"
    call i32 sign -1                REM ; set /a "sign=-1"
)

call i32 precision 50               REM ; set /a "precision=50"
call i32 temp 0                     REM ; set /a "temp=0"

for /l %%i in (0, 1, %precision%) (
    for /l %%j in (0, 1, %precision%) (
        call i32 poweredneg -1 * -1     REM ; set /a "poweredneg=-1,poweredneg=%poweredneg%*%poweredneg%"
    )
    for /l %%k in (0, 1, %precision% * %precision% * %%i + 1) (
        call i32 powereds %%k           REM ; set /a "powereds=%%k"
    )
    call i32 factmp 2 * %%i + 1         REM ; set /a "factmp=2*%%i+1"
    for /l %%l in (0, -1, %factmp%) (
        call i32 tmptmp %factmp%        REM ; set /a "tmptmp=%factmp%"
        call i32 fac %%l * %factmp%     REM ; set /a "fac=%%l * %factmp%"
    )
    call i32 temp %temp% + %poweredneg% * %powereds% / %fac%        REM ; set /a "temp=%temp%+%poweredneg%*%powereds*/%fac%"
)

pause