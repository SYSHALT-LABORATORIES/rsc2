@echo off
setlocal enableextensions
setlocal enabledelayedexpansion
mode 80,25
title static
color 0f
:DefineThings
Sound Play static.wav -1
goto upd

:upd
batbox /k_
if %errorlevel% equ 27 (
	Sound Stop static.wav
	goto:eof
)
batbox /c 0xF0 /a 0xB0
batbox /g !random:~0,2! !random:~0,2!
batbox /c 0x0F /a 0xB1
batbox /g !random:~0,2! !random:~0,2!
batbox /c 0xF0 /a 0xB2
goto:upd