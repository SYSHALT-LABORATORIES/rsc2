@echo off
mode 80,25

call i32 divw 80 / 4        REM ; set /a "divw=80/4"
call i32 divh 25 / 4        REM ; set /a "divh=25/4"

:tiletest
for /l %%i in (0,1,%divw%) (
  echo A
  batbox /g 0 %%i
  for /l %%j in (0,1,%divh%) (
    echo B 
    batbox /g %%i %%j  
  )
)
pause>nul
goto:eof
