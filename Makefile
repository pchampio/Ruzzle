CC=gcc
OBJ= gener_gril.o
FLAG=-Wall
monprog: $(OBJ) lib_custom.h
	$(CC) -o monprog $(OBJ) $(FLAG)
monprog.o: monprog.c
	$(CC) -c monprog.c $(FLAG)
clean:
	rm *.o
