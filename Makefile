CC = gcc
CFLAGS = -g3 -O0 -std=c99

all: TANGO

TANGO : ./obj/main.o ./obj/tree.o 
	$(CC) ./obj/main.o ./obj/tree.o -o ./bin/main $(CFLAGS)

./obj/main.o: ./src/main.c
	$(CC) -c ./src/main.c -o ./obj/main.o

./obj/tree.o: ./src/tree.c
	$(CC) -c ./src/tree.c -o ./obj/tree.o

clean:
	rm ./obj/*.o
