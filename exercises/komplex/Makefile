CFLAGS = -Wall -std=gnu11
LDLIBS = -lm
CC=gcc

all: out.txt;
	cat out.txt

out.txt: main;
	./$< > $@

main: main.o komplex.o;
	$(CC) $(LDFLAGS) $^ -o $@ $(LDLIBS)

main.o:main.c komplex.h

komplex.o:komplex.c komplex.h

clean:
	$(RM) *.o main out.txt

