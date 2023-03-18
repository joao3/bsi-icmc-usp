INDEX=packages/index/index.c packages/index/indexList.c packages/index/indexFileHandler.c
STUDENT=packages/student/student.c packages/student/studentFileHandler.c packages/student/studentIndexFile.c
MAIN=main.c
BINARY=main

all:
	gcc $(MAIN) $(INDEX) $(STUDENT) -o $(BINARY) -Wall

run:
	./$(BINARY)

debug:
	gcc -g $(MAIN) $(INDEX) $(STUDENT) -o $(BINARY) -DDEBUG -Wall -lm

valgrind:
	valgrind --tool=memcheck --leak-check=full  --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./$(BINARY)

clean:
	rm -f *.o