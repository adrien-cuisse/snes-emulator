
CC= gcc
CFLAGS= -Wall -ansi -pedantic -Werror -Wextra
LDFLAGS=

SRC= $(shell find . -type f -name '*.c')
OBJ= $(SRC:.c=.o)

BINARY= emulator

$(BINARY): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm $(OBJ) 2>/dev/null; true

cleanall: clean
	rm $(BINARY) 2>/dev/null; true

run: $(BINARY)
	./$(BINARY)
