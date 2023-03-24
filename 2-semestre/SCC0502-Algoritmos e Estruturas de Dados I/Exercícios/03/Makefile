UTIL=src/pilha.c src/baralho.c src/carta.c src/blackjack.c src/util.c
MAIN=main.c
BINARY=main

all:
	gcc $(MAIN) $(UTIL) -o $(BINARY) -Wall -Werror

run:
	./$(BINARY)

debug:
	gcc -g $(MAIN) $(UTIL) -o $(BINARY) -DDEBUG -Wall -lm

valgrind:
	valgrind --tool=memcheck --leak-check=full  --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./$(BINARY)

clean:
	rm -f *.o