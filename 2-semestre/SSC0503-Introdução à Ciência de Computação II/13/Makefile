all:
	gcc main.c quick.c -o main -Wall -lm

run:
	./main

valgrind:
	valgrind --leak-check=full ./main