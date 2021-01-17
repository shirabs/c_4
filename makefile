all: frequency

frequency: trie.o main.o
	gcc -g  -Wall -o frequency trie.o main.o

trie.o: trie.c trie.h
	gcc -g  -Wall -c trie.c

main.o: main.c
	gcc -g  -Wall  -c main.c

.PHONY: clean all mymaths mymathd

clean:
	rm -f *.o *.a *.so frequency