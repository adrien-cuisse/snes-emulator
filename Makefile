
CC= gcc
CFLAGS= -Wall -ansi -pedantic -Werror -Wextra
LDFLAGS=

SRC_DIRECTORY= src
OBJ_DIRECTORY= obj
BIN_DIRECTORY= bin

SRC_COMMON= $(shell find $(SRC_DIRECTORY)/common -type f -name '*.c')
SRC_SNES = $(shell find $(SRC_DIRECTORY)/snes -type f -name '*.c')

OBJ_COMMON= $(subst $(SRC_DIRECTORY)/,$(OBJ_DIRECTORY)/,$(SRC_COMMON:.c=.o))
OBJ_SNES= $(subst $(SRC_DIRECTORY)/,$(OBJ_DIRECTORY)/,$(SRC_SNES:.c=.o))


SNES_EMULATOR= snes
BINARIES= $(SNES_EMULATOR)

default: $(BINARIES)

# Creates the directory architecture
arch:
	@mkdir $(subst src/,obj/,$(shell find src/ -type d)) 2>/dev/null; true

# Generil rule to compile sources
$(OBJ_DIRECTORY)/%.o: $(SRC_DIRECTORY)/%.c | arch
	$(CC) $(CFLAGS) -c $^ -o $@

$(SNES_EMULATOR): $(OBJ_COMMON) $(OBJ_SNES)
	$(CC) $(LDFLAGS) $^ -o $(BIN_DIRECTORY)/$@

clean:
	rm $(OBJ_COMMON) $(OBJ_SNES) 2>/dev/null; true

cleanall: clean
	rm $(addprefix $(BIN_DIRECTORY)/, $(BINARIES)) 2>/dev/null; true

