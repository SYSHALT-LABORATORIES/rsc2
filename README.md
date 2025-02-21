# rsc²

custom CLI DE for Server2003 with a kernel (partial-OS)

# The syscall.bat incident (1930)

very long story shortened: we were making a custom OS for 1930 with a ROM interpreter

and a custom compiler that made the RPGMaker files a garbled binary file

after the game failed miserably, we decided to make this a totally separated thing

# Compilation

please compile using ```i686-mingw-w32-gcc file.c -o file.exe```

this is supposed to run in an x86 environment

if you want to make a port for x64 take note: **IT MIGHT NOT RUN CORRECTLY!**

# Installation steps

- make a file at Start Menu/Launch and paste ```@echo off && cd c:\ && call mainOS.bat```

copy the repo to C:\ obviously

if needed un-REM the "cd c:\" line at mainOS.bat

# Notice

## Maybe

### Just Maybe

---

I can use `batbox.exe` instead of `conio.h` since the original one needs 

DOSBOX

