CC = gcc
CC += -m32 -no-pie -fno-pie
CFLAGS += -std=gnu99

test1 = 5
test2 = 3

.DELETE_ON_ERROR:

.PHONY: all
all: f

f: f.o f.c
	$(CC) $(CFLAGS) -o $@ $^ 
	
f.o: f.asm
	nasm -f elf32 -o $@ $< 
	
.PHONY: clean
clean:
	rm -rf *.o f
	
.PHONY: test
test: f
	@echo "First test: 5 -> 15.500000"
	echo "$(test1)" | ./f
	@echo "First test: 3 -> 10.500000"
	echo "$(test2)" | ./f
