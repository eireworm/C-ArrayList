# Define the compiler and flags
CC = clang
CFLAGS = -Wall -Werror -Iinclude

# Define the source files, object files, and target binary
SRC = $(wildcard src/*.c)
OBJ = $(SRC:src/%.c=obj/%.o)
TARGET = bin/main

# Default target
all: $(TARGET)

# Rule to build the target binary
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Rule to compile source files into object files
obj/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target to remove generated files
clean:
	rm -f $(OBJ) $(TARGET)
