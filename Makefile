CC=gcc
OBJ=./src/*.c
LIB=./include/*.h
FLAG=-Wall -g
DOCDIR=./doc
OBJDIR=./bin

MAKE=-f makefile

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
rmdoc:
	rm -rf $(DOCDIR)
doc: rmdoc
	doxygen
test:
	cd ./tests && make $(MAKE)
test_clean:
	cd ./tests && make $(MAKE) clean
