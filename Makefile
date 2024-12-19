# Variables
CC = gcc
CFLAGS = -Wall -Werror -g
AR = ar
ARFLAGS = rcs
LIB_NAME = libcalc.a
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
TARGET = $(BIN_DIR)/my_calculator
PREFIX = /usr/local
BINDIR = $(PREFIX)/bin
LIBDIR = $(PREFIX)/lib
MAIN_SRC = $(SRC_DIR)/main.c

# Source and Object files
SRCS = $(filter-out $(MAIN_SRC), $(wildcard $(SRC_DIR)/*.c))
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Rules
all: $(TARGET)

$(TARGET): $(OBJS) $(LIB_NAME) $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $(MAIN_SRC) -L. -lcalc -lm

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB_NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

$(OBJ_DIR) $(BIN_DIR):
	mkdir -p $@

install: all
	install -d $(BINDIR) $(LIBDIR)
	install -m 755 $(TARGET) $(BINDIR)
	install -m 644 $(LIB_NAME) $(LIBDIR)

uninstall:
	rm -f $(BINDIR)/my_calculator
	rm -f $(LIBDIR)/$(LIB_NAME)

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR) $(LIB_NAME)

.PHONY: all clean install uninstall