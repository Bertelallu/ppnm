CC = gcc
CFLAGS = -std=gnu99
CFLAGS += -Wall
LDFLAGS = -I.
LDLIBS = -lm

out.txt: eps 
	./$< > $@

eps: eps.o equal.o

eps.o: eps.c
	$(CC) $(CFLAGS) -c eps.c -o eps.o

equal.o: equal.c
	$(CC) $(CFLAGS) -c equal.c -o equal.o

clean:
	$(RM) eps out.txt *.o

