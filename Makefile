CC = gcc

all:
	$(CC) -o vector.ex vector.ex.c

clean:
	rm -f vector.ex