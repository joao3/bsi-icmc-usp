SRC=src/jogo.c src/catalogo.c src/lista.c src/util.c
MAIN=main.c
BINARY=main

all:
	gcc $(MAIN) $(SRC) -o $(BINARY) -Wall

run:
	./$(BINARY)

debug:
	gcc -g $(MAIN) $(SRC) -o $(BINARY) -DDEBUG -Wall -lm

valgrind:
	valgrind --tool=memcheck --leak-check=full  --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./$(BINARY)

clean:
	rm -f *.o