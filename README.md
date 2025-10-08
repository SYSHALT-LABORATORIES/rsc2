# rsc²

custom CLI DE for Server2003 with a kernel (partial-OS)

[![C/C++ CI](https://github.com/SYSHALT-LABORATORIES/rsc2/actions/workflows/c-cpp.yml/badge.svg)](https://github.com/SYSHALT-LABORATORIES/rsc2/actions/workflows/c-cpp.yml)

# Compilation

please compile using ```i686-mingw-w32-gcc file.c -o file.exe```

this is supposed to run in an x86 environment

if you want to make a port for x64 take note: **IT MIGHT NOT RUN CORRECTLY!**

# Installation steps

- make a file at Start Menu/Launch and paste ```@echo off && cd c:\ && call mainOS.bat```

copy the repo to C:\ obviously

if needed un-REM the "cd c:\" line at mainOS.bat
> [!WARNING]
> Installation steps are deprecated.
