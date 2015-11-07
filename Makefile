CC=gcc
OBJ=./src/*.c
LIB=./include/*.h
FLAG=-Wall

OBJDIR=./bin

# ifeq ($(origin SIZE),undefined)
# if
# SIZE=-DN=$(size)
# endif


ifndef size
SIZE=-DN=4
else
SIZE=-DN=$(size)
endif



main: $(OBJ) $(LIB)
	test -d $(OBJDIR) || mkdir $(OBJDIR)
	$(CC) -o $(OBJDIR)/main $(OBJ) $(FLAG) $(SIZE)
main.o: $(OBJDIR)/main.c
	$(CC) -c $(OBJDIR)/main.c $(FLAG) $(SIZE)
clean:
	rm -rf ./$(OBJDIR)
