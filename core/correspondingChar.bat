@echo off
setlocal enableextensions
setlocal enabledelayedexpansion
mode 80,25
color 0a
:upd
batbox /k 
batbox /a %errorlevel%
goto :upd
