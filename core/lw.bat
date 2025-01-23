@echo off
REM upper
set /a "b1=%1,b2=%2,b3=%3,b4=%4"
REM lower
set /a "b5=%5,b6=%6,b7=%7,b8=%8"
set /a "final_addr=%b1%%b2%%b3%%b4%%b5%%b6%%b7%%b8%"