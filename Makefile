CC = gcc
CFLAGS = -Wall -g

LIBNAME = log
PREFIX = /usr/local
INCLUDEDIR = $(PREFIX)/include
LIBDIR = $(PREFIX)/lib

SRC_DIR = src
INC_DIR = include
BUILD_DIR = build

HEADER = $(INC_DIR)/$(LIBNAME).h
SRC = $(SRC_DIR)/$(LIBNAME).c
OBJ = $(BUILD_DIR)/$(LIBNAME).o
STATIC_LIB = $(BUILD_DIR)/lib$(LIBNAME).a

.PHONY: all clean install uninstall

all: $(STATIC_LIB)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(OBJ): $(SRC) | $(BUILD_DIR)
	gcc $(CFLAGS) -c $< -o $@

$(STATIC_LIB): $(OBJ)
	ar rcs $@ $^

install: $(STATIC_LIB) $(HEADER)
	sudo cp $(STATIC_LIB) $(LIBDIR)/
	sudo cp $(HEADER) $(INCLUDEDIR)/

uninstall:
	sudo rm -f $(LIBDIR)/lib$(LIBNAME).a
	sudo rm -f $(INCLUDEDIR)/$(notdir $(HEADER))

clean:
	rm -rf $(BUILD_DIR)
