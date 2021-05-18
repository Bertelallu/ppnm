CFLAGS = -Wall -O1 -std=gnu11 #-DNDEBUG
CFLAGS += $(shell /usr/bin/gsl-config --cflags)
LDLIBS += $(shell /usr/bin/gsl-config --libs)
CC = gcc

default:data.pyxplot.png dataB.pyxplot.png
data.pyxplot.png: data.txt main Makefile out.txt
	echo '\
	set terminal png;\
	set output "$@";\
	set key top left;\
	set tics out;\
	set xlabel "x";\
	set ylabel "y";\
	set title "X function example";\
	plot \
	"data.txt" using 1:2 with points title "yexact"\
	,"data.txt" using 1:3 with points title "ygaet"\
	' | tee tmp.gpi | pyxplot

dataB.pyxplot.png: data.txt main Makefile out.txt
	echo '\
	set terminal png;\
	set output "$@";\
	set key top left;\
	set tics out;\
	set xlabel "x";\
	set ylabel "y";\
	set title "X function example";\
	plot \
	"dataB.txt" using 1:2 with lines title "ygradient"\
	,"dataB.txt" using 1:3 with lines title "yvalue"\
	,"dataB.txt" using 1:4 with lines title "yintegral"\
	,"dataB.txt" using 1:5 with lines title "yexactvalue"\
	' | tee tmp.gpi | pyxplot

out.txt: main 
	./$< > $@ 2>log
    
main: main.o functions.o lineqfunctions.o ann.o
    
clean: 
	$(RM) main *.o out.txt *.png *.gpi