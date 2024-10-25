CC      := clang
CFLAGS  := -std=c11 -Wall -Wextra -Werror -Wpedantic

LIBMX   := libmx.a
SRC_DIR := src
OBJ_DIR := obj
INC_DIR := inc

SRC     := $(wildcard $(SRC_DIR)/*.c)
OBJ     := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

all: $(LIBMX)

$(LIBMX): $(OBJ)
	ar -rcs $@ $^
	
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c 
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@
	
clean: 
	rm -rf $(OBJ_DIR) $(LIBMX)
	
uninstall: clean

reinstall: uninstall all

.PHONY: all clean uninstall reinstall
