CFLAGS = -Wall -O1 -std=gnu11 #-DNDEBUG
CFLAGS += $(shell /usr/bin/gsl-config --cflags)
LDLIBS += $(shell /usr/bin/gsl-config --libs)
CC = gcc

default: out.txt C.png 

C.png: Makefile out_decomp.txt
	echo '\
	set terminal png;\
	set output "$@";\
	set key top left;\
	set tics out;\
	set xlabel "N (Matrix of size NxN)";\
	set ylabel "Time (s)";\
	set title "Performance of our function compared to GSL: QR-Decomposition";\
    a=1; b=3; f(x)=a*x**b ;\
	c=1; d=2; g(x)=c*x**d ;\
	fit f(x) "out_decomp.txt" using 1:2 via a,b ;\
	fit g(x) "out_gsl.txt" using 1:2 via c,d ;\
	plot \
	"out_decomp.txt" using 1:2 with points title "Our decomposition"\
	,"out_gsl.txt" using 1:2 with points title "Gsl decomposition"\
    , f(x) with lines title sprintf("%3.1f*10^-^9*n^{%3.1f}",a*1000000000,b)\
	, g(x) with lines title sprintf("%3.1f*10^-^9*n^{%3.1f}",c*1000000000,d)\
	' | gnuplot

out.txt: main 
	./$< > $@
        
main: main.c functions.c

out_decomp.txt: main

clean: 
	$(RM) main *.o *.txt *.gpi *.png *.log
