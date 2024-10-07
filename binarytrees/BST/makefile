# Naming the Project
PROJ_NAME=main

# Sets the gcc compiller as the one used for building the files.
CC=gcc

# Compiller Flags
CC_FLAGS=-Wall -O3 -Wextra -g

# Sets the main file as variable, making it easier if we want to alter it later on.
TARGET=$(PROJ_NAME)

# Assign the word objects as the variable OBJ_DIR.
OBJ_DIR=objects

# List of files that will have an objects corresponding file in the objects folder.
OBJECTS= $(patsubst ./source/%.c, $(OBJ_DIR)/%.o, $(wildcard ./source/*.c))

# Specifies hello as the standart target for make.
all: $(OBJ_DIR) $(TARGET)

# $@ refers to the $(TARGET), which is main in this case; $^ refers to the dependencies of the target, .o files in this case.
$(TARGET): $(OBJECTS)
	$(CC) $(CC_FLAGS) $^ -o $@ 

# Establishes that every .o file should be built by its corresponding .c and .h files.	
$(OBJ_DIR)/%.o: ./source/%.c | $(OBJ_DIR)
	$(CC) $(CC_FLAGS) -c $< -o $@  

# Creates the objects folder
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Defines a function to clear the files built with this makefile, start a clean build on the next execution.	
clean:
	rm -rf $(TARGET) ./objects/

# The PHONY command ensures that make commands will run what is stated in this file, regardless if there are files named clean or all in the project's folder.
.PHONY: all clean