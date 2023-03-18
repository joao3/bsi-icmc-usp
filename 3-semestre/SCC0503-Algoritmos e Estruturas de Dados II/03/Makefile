BTREE=packages/bTree/bTree.c
STUDENT=packages/student/student.c packages/student/studentFileHandler.c packages/student/studentBTree.c
IO=packages/ReadInput/ReadInput.c
MAIN=main.c
BINARY=main

all:
	gcc $(MAIN) $(BTREE) $(IO) $(STUDENT) -o $(BINARY) -Wall

run:
	./$(BINARY)

debug:
	gcc -g $(MAIN) $(BTREE) $(IO) $(STUDENT) -o $(BINARY) -DDEBUG -Wall -lm

valgrind:
	valgrind --tool=memcheck --leak-check=full  --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./$(BINARY)

clean:
	rm -f *.o