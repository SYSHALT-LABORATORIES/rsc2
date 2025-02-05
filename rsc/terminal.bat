@echo off
setlocal enabledelayedexpansion
setlocal enableextensions

cls
title shell
call assembler.bat
:MAIN
set /p "command=> "
%command%
goto:MAIN