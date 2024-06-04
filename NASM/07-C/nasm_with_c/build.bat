@echo off

rem скомпилировать файл main.c в объектный файл main.obj
gcc -m32 -c main.c -o main.o

rem скомпилировать файл add.asm в объектный файл add.o
"D:/Program Files (x86)/SASM/NASM/nasm.exe" --gprefix _ -f win32 add.asm -o add.o

rem линкуем скомиленные asm и c файлы
gcc -m32 main.o add.o -o program.exe

rem запустить исполняемый файл program.exe
program.exe

rem prog.exe

rem pause
