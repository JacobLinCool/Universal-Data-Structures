CC = gcc

all:
	$(CC) -o vector.ex ex/vector.ex.c
	$(CC) -o deque.ex ex/deque.ex.c
	$(CC) -o xor-list.ex ex/xor-list.ex.c

test:
	$(CC) -o ./deque.test test/deque.test.c && ./deque.test

clean:
	rm -f *.ex *.test

.PHONY: all test clean