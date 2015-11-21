CC ?= gcc
CFLAGS = -g -Wall -pedantic --std=gnu99
LDFLAGS = -Lcu/ -lcu

OBJS = t1.o test.o recherche_dictio.o

SIZE=-DN=4

all: test

test: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) $(SIZE)

%.o: %.c %.h
	$(CC) $(CFLAGS) -c -o $@ $< $(SIZE)
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< $(SIZE)

clean:
	rm -f *.o test

.PHONY: all clean
