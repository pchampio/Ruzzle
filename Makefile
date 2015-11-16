CC=gcc
OBJ=./src/*.c
LIB=./include/*.h
FLAG=-Wall
DOCDIR=./doc
OBJDIR=./bin


ifndef size
SIZE=-DN=4
else
SIZE=-DN=$(size)
endif

ifeq ($(size),1)
SIZE=-DN=4
endif



main: $(OBJ) $(LIB)
	test -d $(OBJDIR) || mkdir $(OBJDIR)
	$(CC) -o $(OBJDIR)/main $(OBJ) $(FLAG) $(SIZE)
main.o: $(OBJDIR)/main.c
	$(CC) -c $(OBJDIR)/main.c $(FLAG) $(SIZE)
clean:
	rm -rf $(OBJDIR)
	rm -rf $(DOCDIR)
doc:
	doxygen
