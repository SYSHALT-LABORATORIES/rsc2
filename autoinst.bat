@echo off
setlocal enableextensions
set "_fautostart=@echo off&&cd / &&call mainOS.bat"
set "_fstabloc=%AllUsersProfile%\Start Menu\Startup"
set "_fstabloc10="


echo ===========================================
echo.
echo.
echo     WELCOME TO THE RSC INSTALL PROCESS
echo.
echo.
echo ===========================================

if NOT exist %_fstabloc% (
    cls
    echo ERROR COULD NOT PROCEED WITH INSTALL
    ECHO WINDOWS SERVER 2003 R2 IS NEEDED
)

if EXIST %_fstabloc% (
    @echo on
    cd /
    echo %_fautostart% > "~tmp.lck"
    copy "~tmp.lck" "%AllUsersProfile%\Start Menu\Startup"
    pushd %_fstabloc%
    ren "~tmp.lck" plead.bat
    @echo off

    echo File copied.
)

IF EXIST C:\inf.rsc (
    echo Already installed
    pause>nul
)

set "_fstabloc10=                                       "

REM malloc
popd
cd %~dp0 REM expansion to dir where files would be?????
copy * c:\
cd c:\
echo installed>inf.rsc 
copy /b inf.rsc inf.rsc |^copy /b inf.rsc inf.rsc
shutdown -r /t 0>nul
