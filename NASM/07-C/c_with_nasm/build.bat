@echo off

rem скомпилировать файл hello.c в объектный файл hello.obj
gcc -Wall -Wextra -pedantic -c hello.c -o hello.o

rem скомпилировать файл main.asm в объектный файл main.o
"D:/Program Files (x86)/SASM/NASM/nasm.exe" -f win64 main.asm -o main.o

rem линкуем .asm и .c
gcc main.o hello.o -o program.exe

rem запустить исполняемый файл program.exe
program.exe

rem pause
