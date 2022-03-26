CC = gcc

all:
	$(CC) -o vector.ex ex/vector.ex.c

clean:
	rm -f vector.ex