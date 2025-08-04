CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c11
LDFLAGS = -lcs50

uppercase1: uppercase1.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

clean:
	rm -f uppercase1

.PHONY: clean