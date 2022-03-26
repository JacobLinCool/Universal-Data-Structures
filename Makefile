CC = gcc

all:
	$(CC) -o vector.ex ex/vector.ex.c
	$(CC) -o deque.ex ex/deque.ex.c
	$(CC) -o xor-list.ex ex/xor-list.ex.c

clean:
	rm -f *.ex
