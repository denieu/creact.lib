#------------------------------------------------------------------------------#
# project-pattern.c
#
# Author: Daniel Wojcickoski
# Date: 2021/05/23
# Url: https://github.com/denieu/project-pattern.c
#
# MIT License - Copyright (c) 2021 Daniel Wojcickoski
#------------------------------------------------------------------------------#

#Program version
V_MAJOR=0
V_MINOR=1
V_PATCH=0
VERSION=-D V_MAJOR=$(V_MAJOR) -D V_MINOR=$(V_MINOR) -D V_PATCH=$(V_PATCH)
#Compiler
COMPILER=gcc
#Executable name
FILENAME=creact
#Directory of binary files
BIN=./bin
#Directory of .h files
INCLUDE=./includes
#Directory of object files
OBJ=./obj
#Directory of .c files
SRC=./src
#Directory of lib files
LIB=./libs
#Directory of .rc files
RC=./resources

#Compiler flags
FLAGS= -o
#Project libs
#Examples: -lconio -lpthread
LIB_FLAGS=
#Libs to link with the compiler
LIBS= -lm -L$(LIB) $(LIB_FLAGS)

#Change .c files to .o files
#Files .c
C_SRC=$(wildcard $(SRC)/*.c)
#Remove prefix and suffix
OBJ_CLEAN=$(notdir $(basename $(C_SRC)))
#Add new prefix and suffix
OBJ_FILES=$(addprefix $(OBJ)/, $(addsuffix .o, $(OBJ_CLEAN)))

#Commands
.PHONY: all clean

#Make .res .o and final binary
all: compile $(FILENAME)

#Make .o files
compile: $(OBJ_FILES)

#Make .o file macro
$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
	$(COMPILER) $(VERSION) $(FLAGS) -c $< -I $(INCLUDE) -o $@

#Make final binary macro
$(FILENAME): $(OBJ_FILES) $(RES_FILES)
	$(COMPILER) $(FLAGS) $(RES_FILES) $(OBJ_FILES) $(LIBS) -o $(BIN)/$@

#Run program
run:
	$(BIN)/$(FILENAME)

#Clean executable and objects
clean:
	rm -f $(OBJ)/*.o
	rm -f $(OBJ)/*.res
	rm -f $(BIN)/$(FILENAME)