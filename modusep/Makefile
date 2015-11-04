CC=gcc
OBJ=*.c
FLAG=-Wall
main: $(OBJ) *.h
	$(CC) -o main $(OBJ) $(FLAG)
main.o: main.c
	$(CC) -c main.c $(FLAG)
clean:
	rm *.o
