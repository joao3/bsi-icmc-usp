UTIL=ponto.c caminho.c
MAIN=main.c
BINARY=main

all:
	gcc $(MAIN) $(UTIL) -o $(BINARY) -Wall -Werror -lm

run:
	./$(BINARY)
	
debug:
	gcc -g $(MAIN) $(UTIL) -o $(BINARY) -DDEBUG -Wall -lm

valgrind:
	valgrind --tool=memcheck --leak-check=full  --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./$(BINARY)

clean:
	rm -f *.o