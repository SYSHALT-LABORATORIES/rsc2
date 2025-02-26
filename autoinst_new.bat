@echo off
setlocal enableextensions
set "_fautostart=@echo off&&cd / &&call mainOS.bat"
set "_fstabloc=%AllUsersProfile%\Start Menu\Startup"   
REM this maps to the startup folder in xp
REM actually the intended is Server 2003 since it's closer to longhorn 
REM (branches were merged a lot), and it has new commands such as "timeout"

if not exist %_fstabloc% (
    echo Error: This is not a Windows XP system        
    pause
    exit /b 1
)

if exist %_fstabloc%\plead.bat (
    echo This system is already configured.
    echo Do you want to update?
    choice /c yn /m "Yes/No"
    goto:doit
)

if exist %_fstabloc% (
    goto:doit
)

:doit
echo %_fautostart% > "%_fstabloc%\AUTOINST_NEW.bat"
pushd %_fstabloc% && ren "AUTOINST_NEW.bat" plead.bat
popd
copy * c:\
shutdown -r /t 0>nul
