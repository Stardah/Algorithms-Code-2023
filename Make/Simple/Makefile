all: main.exe

clean:
	rm -f *.o all
	rm -f *.exe all

main.exe: add.o sub.o main.o	
	gcc -m32 main.o sub.o add.o -o main.exe

CC := gcc # C compiler variable
CFLAGS := -m32 # C compiler flags

ASMC := "D:/Program Files (x86)/SASM/NASM/nasm.exe"
ASMFLAGS := --gprefix _ -f win32 

# $@ - target name
# $? - изменённые зависимости (обновленные файлы)
# $^ - зависимости (prerequisites)
# $< - первая зависимость
# % - wildcard

%.o : %.c 
	$(CC) $(CFLAGS) -c  $< -o $@

%.o : %.asm 
	$(ASMC) $(ASMFLAGS) $< -o $@
