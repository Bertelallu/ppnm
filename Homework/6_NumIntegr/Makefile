CFLAGS = -Wall -O1 -std=gnu11 #-DNDEBUG
CFLAGS += $(shell /usr/bin/gsl-config --cflags)
LDLIBS += $(shell /usr/bin/gsl-config --libs)
CC = gcc

out.txt: main 
	./$< > $@
    
main: main.c functions.c
    
clean: 
	$(RM) main main.o functions.o *.txt *.png *.gpi