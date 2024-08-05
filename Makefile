SRC_DIR=src

BUILD_DIR=build
BIN_DIR=$(BUILD_DIR)/bin
OBJ_DIR=$(BUILD_DIR)/objects

TESTS_DIR=tests
TESTS_UTILS_DIR=$(TESTS_DIR)/utils
TESTS_BUILD_DIR=$(TESTS_DIR)/tests_build
TESTS_BIN_DIR=$(TESTS_BUILD_DIR)/tests_bin
TESTS_OBJ_DIR=$(TESTS_BUILD_DIR)/tests_objects

#C_SOURCE=$(SRC_DIR)/LinkedList.c $(SRC_DIR)/ResizableArray.c
C_SOURCE=src/LinkedList.c src/ResizableArray.c
TESTS_SOURCE=$(TESTS_DIR)/TestLinkedList.c $(TESTS_DIR)/TestResizableArray.c
TESTS_UTILS_SOURCE=$(wildcard $(TESTS_UTILS_DIR)/*.c)

OBJ=$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(C_SOURCE))
TESTS_OBJ=$(patsubst $(TESTS_DIR)/%.c,$(TESTS_OBJ_DIR)/%.o,$(TESTS_SOURCE))
TESTS_UTILS_OBJ=$(patsubst $(TESTS_UTILS_DIR)/%.c,$(TESTS_OBJ_DIR)/%.o,$(TESTS_UTILS_SOURCE))

BIN=$(patsubst $(SRC_DIR)/%.c,$(BIN_DIR)/%,$(C_SOURCE))
TESTS_BIN=$(patsubst $(TESTS_DIR)/%.c,$(TESTS_BIN_DIR)/%,$(TESTS_SOURCE))

CC=gcc
CC_FLAGS=-Wall -Werror -Wextra -pedantic

all: clean $(OBJ)

tests: clean $(TESTS_BIN)

clean:
ifeq ($(OS),Windows_NT)
	cmd /c del $(subst /,\,$(OBJ) $(TESTS_OBJ) $(TESTS_UTILS_OBJ) $(BIN) $(TESTS_BIN) $(TESTS_BIN:=.exe))
else
	rm $(BIN_DIR)/* $(OBJ_DIR)/* $(TESTS_BIN_DIR)/* $(TESTS_OBJ_DIR)/*
endif

# === For "all" ===
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(SRC_DIR)/%.h
	$(CC) $(CC_FLAGS) -c $< -o $@

# === For "tests" ===
$(TESTS_BIN): $(TESTS_BIN_DIR)/Test%: $(TESTS_OBJ_DIR)/Test%.o $(OBJ_DIR)/%.o $(TESTS_OBJ_DIR)/utils.o
	$(CC) $(CC_FLAGS) $^ $> -o $@

$(TESTS_OBJ): $(TESTS_OBJ_DIR)/%.o: 
	$(CC) $(CC_FLAGS) -c $(TESTS_DIR)/$*.c -o $@

$(TESTS_UTILS_OBJ): $(TESTS_OBJ_DIR)/%.o: $(TESTS_UTILS_DIR)/%.c $(TESTS_UTILS_DIR)/%.h
	$(CC) $(CC_FLAGS) -c $< -o $@
