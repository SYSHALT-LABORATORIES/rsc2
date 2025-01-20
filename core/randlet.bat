@echo off
setlocal enableextensions
setlocal enabledelayedexpansions
mode 80,25
cls
color 09
for /l %%i in (0, 1, 50) do (
	batbox /d " " && batbox /a 0xB0 
	batbox /d "%%i" && batbox /a 0xB2
	batbox /a 0xDB && batbox /d "  " && batbox /a 0xB1
	type bel.snd
)