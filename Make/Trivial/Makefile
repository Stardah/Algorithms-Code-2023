all: add.o sub.o main.o main.exe

# --gprefix _ вставляет префикс "_" перед каждой функцией
add.o: add.asm
	"D:/Program Files (x86)/SASM/NASM/nasm.exe" --gprefix _ -f win32 add.asm -o add.o

sub.o: sub.c sub.h
	gcc -m32 -c sub.c -o sub.o
	
main.o: main.c sub.h
	gcc -m32 -c main.c -o main.o

main.exe: add.o sub.o main.o	
	gcc -m32 main.o sub.o add.o -o main.exe

clean:
	rm -f *.o all
	rm -f *.exe all

# add.o: add.asm
# 	echo "Did nothing"