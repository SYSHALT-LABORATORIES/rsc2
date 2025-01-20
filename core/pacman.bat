@echo off
setlocal enableextensions
setlocal enabledelayedexpansion
mode 80,25
color 0a
title pacman

:DefineThings
set /a PlyrX=40
set /a PlyrY=13
set "PACMAN= "
Set /a "row=0"
Set /a "col=0"
Set "spr_index=1"
Sound Play waka_waka.wav -1
goto upd

:upd
rem batbox /a 0xDB
set /a "prevRow=%row%"
set /a "prevCol=%col%"
Set /a "moved=0"
Sprite %row% %col% pac_1.spr
batbox /k
cls
if %errorlevel% equ 327 (
	Set /a PlyrY-=1
	Set /a "moved=1,row-=1"
)
if %errorlevel% equ 335 (
	set /a PlyrY+=1
	set /a "moved=1,row+=1"
)
if %errorlevel% equ 330 (
	set /a PlyrX-=1
	set /a "moved=1,col-=1"
)
if %errorlevel% equ 332 (
	set /a PlyrX+=1
	set /a "moved=1,col+=1"
)

if %errorlevel% equ 27 (
	Sound Stop waka_waka.wav
	goto:eof
)
batbox /g %PlyrX% %PlyrY%
If 1 Equ %moved% (
Sprite %prev_row% %prev_col% pac_erase.spr 
) Else (
Sprite %row% %col% pac_1.spr
)
Set /a "spr_index=(spr_index %% 2) + 1"
goto :upd
