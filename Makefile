# This Makefile is only for Linux! 
# Valgrind / libASan do not work in Windows!

SRC := src
OBJ := obj
BIN := bin

SOURCES := $(wildcard $(SRC)/*.c)
OBJECTS := $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SOURCES))
BINARY  := $(BIN)/main.exe

CC     := gcc
CFLAGS := -O0 -g -std=c17

.PHONY, .SILENT: all create-dirs run clean 

all: clean create-dirs $(BINARY)

$(BINARY): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

create-dirs:
ifeq ($(OS),Windows_NT)
	if not exist "$(OBJ)" mkdir $(OBJ)
	if not exist "$(BIN)" mkdir $(BIN)
else
	mkdir -p $(OBJ) $(BIN)
endif

run:
	./$(BINARY)

clean:
ifeq ($(OS),Windows_NT)
	if exist "$(OBJ)" rmdir /s /q $(OBJ)
	if exist "$(BIN)" rmdir /s /q $(BIN)
else
	rm -rf $(OBJ) $(BIN)
endif
