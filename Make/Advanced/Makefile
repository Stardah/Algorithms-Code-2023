TARGET_EXEC := main
BUILD_DIR := ./build
SRC_DIR := ./src

# SRCS := $(wildcard $(SRC_DIR)/*.c $(SRC_DIR)/*.asm)
SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

#
# Compilers and flags
#
CC = gcc # C compiler variable

# -MMD -MP сгенерируют .d файлы
# а список INC_FLAGS позволит их подхватить
CFLAGS = -m32 $(INC_FLAGS) -MMD -MP # C compiler flags

ASMC = "D:/Program Files (x86)/SASM/NASM/nasm.exe"
ASMFLAGS = --gprefix _ -f win32 

$(BUILD_DIR)/%.o : %.c 
	$(CC) $(CFLAGS) -c  $< -o $@

$(BUILD_DIR)/%.o : %.asm 
	$(ASMC) $(ASMFLAGS) $< -o $@

$(BUILD_DIR)/%.exe: $(BUILD_DIR)/%.o
	$(CC) $(OBJS) -o $@

clean:
	rm -f $(BUILD_DIR)/*.o all
	rm -f $(BUILD_DIR)/*.exe all

debug:
	@echo $(SRCS)
	# @echo $(OBJS)
