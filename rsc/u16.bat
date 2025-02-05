@echo off
set /a %1=%2
if %1 gtr 65536 (set /a %1=65536)
if %1 lss 0 (set /a %1=0)