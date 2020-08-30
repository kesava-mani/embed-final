#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material.
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Makefile for the project with multiple platform support - x86 and arm
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <file>.i - generates the corresponding pre-processed file
#      <file>.asm - generates the corresponding assembly file
#      <file>.o - generates the corresponding object file
#      <file>.d - generates the corresponding dependency file
#      compile-all - compiles all c files in ./src directory
#      build  - compiles and links to produce executable  in current directory.
#								Also, the corresponding map and assembly is generated.
#      clean - cleans all generated files such as .o, .i, .d, .asm,
# 						 .map, .out in current directory
#
# Platform Overrides:
#      PLATFORM - HOST/MSP432 - build the project for input architecture
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = HOST

# Generic variable defines
VPATH     =./src
BASENAME  = c1_final
TARGET    = $(BASENAME).out
COMMON    = -Wall -Werror -g -O0 -std=c99

# Generate files for corresponding .c
PREP = $(SOURCES:.c=.i)
ASMB = $(SOURCES:.c=.asm)
DEPS = $(SOURCES:.c=.d)
OBJS = $(SOURCES:.c=.o)

# Architectures Specific Flags
CPU   = cortex-m4
ARCH  = thumb
SPECS = nosys.specs

ifeq ($(VERBOSE), YES)
	VER_VALUE = TRUE
else
	VER_VALUE = FALSE
endif

# Compiler Flags and Defines
ifeq ($(PLATFORM), HOST)
	CC          = gcc
	ASM         = objdump -d
	CFLAGS      = $(COMMON)
	CPPFLAGS    = -D$(PLATFORM) -DVERBOSE=$(VER_VALUE) -DCOURSE1
	LDFLAGS     = -Wl,-Map=$(BASENAME).map
	SIZE        = size
else
	CC          = arm-none-eabi-gcc
	ASM         = arm-none-eabi-objdump -d
	CFLAGS      = $(COMMON) -mfpu=fpv4-sp-d16 \
                -mfloat-abi=softfp -march=armv7e-m -mcpu=$(CPU) -m$(ARCH)
	CPPFLAGS    = -D$(PLATFORM) -DVERBOSE=$(VER_VALUE) -DCOURSE1
	LINKER_FILE = ./msp432p401r.lds
	LDFLAGS     = -Wl,-Map=$(BASENAME).map -T $(LINKER_FILE) --specs=$(SPECS)
	SIZE        = arm-none-eabi-size
endif

# Make recipes start
# Pre-processed file recipe
%.i : %.c
	$(CC) -E $< $(INCLUDES) $(CPPFLAGS) $(CFLAGS) -o $@

# Assemble file recipe
%.asm : %.c
	$(CC) -S $< $(INCLUDES) $(CPPFLAGS) $(CFLAGS) -o $@

# Object file recipe
%.o : %.c
	$(CC) -c $< $(INCLUDES) $(CPPFLAGS) $(CFLAGS) -o $@

# Dependency file recipe
%.d : %.c
	$(CC) $(INCLUDES) $(CPPFLAGS) $(CFLAGS) -M $< -o $@

# All source files compile only recipe
compile-all : $(OBJS) #$(DEPS)

# Spotlight recipe
build : compile-all
	$(CC) $(LDFLAGS) $(OBJS) -o $(TARGET)
	$(ASM) $(TARGET) > $(BASENAME).asm
	$(SIZE) -Atx $(TARGET)
	$(SIZE) $(TARGET)

# Cleaning recipe
clean :
	rm -f *.o *.asm *.d *.i $(BASENAME).*

# Phony directives for...
.PHONY : compile-all build clean
