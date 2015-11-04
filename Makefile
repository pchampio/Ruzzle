CC=gcc
OBJ=./src/*.c
LIB=./include/*.h
FLAG=-Wall
SIZE=-DN=4
OBJDIR=./bin
# SIZE=-DN=4
ifeq ($(size), 1)  #at this point, the makefile checks if FEATURE is ==1
SIZE=-DN=$(size)
endif
ifeq ($(size), 2)
SIZE=-DN=$(size)
endif
ifeq ($(size), 3)
SIZE=-DN=$(size)
endif
ifeq ($(size), 4)
SIZE=-DN=$(size)
endif
ifeq ($(size), 5)
SIZE=-DN=$(size)
endif
ifeq ($(size), 6)
SIZE=-DN=$(size)
endif


main: $(OBJ) $(LIB)
	test -d $(OBJDIR) || mkdir $(OBJDIR)
	$(CC) -o $(OBJDIR)/main $(OBJ) $(FLAG) $(SIZE)
main.o: $(OBJDIR)/main.c
	$(CC) -c $(OBJDIR)/main.c $(FLAG) $(SIZE)
clean:
	rm -rf ./$(OBJDIR)
