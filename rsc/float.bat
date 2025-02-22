@echo off
set /a intparam = %1
set "strparam=%intparam%"
for /f %%n in ('cscript //nologo eval.vbs "%strparam%"') do (
  set res=%%n
)
rem echo %res%
