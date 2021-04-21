CFLAGS = -Wall -O1 -std=gnu11 #-DNDEBUG
CFLAGS += $(shell /usr/bin/gsl-config --cflags)
LDLIBS += $(shell /usr/bin/gsl-config --libs)
CC = gcc

default: Error.gnuplot.png ErrorError.gnuplot.png

Error.gnuplot.png: main Makefile A.txt B.txt out.txt
	echo '\
	set terminal png;\
	set output "$@";\
	set key top left;\
	set tics out;\
	set xlabel "N";\
	set ylabel "error";\
	set title "error comparision";\
	a=1; b=-0.5; f(x)=a*x**b ;\
	c=1; d=-0.5; g(x)=c*x**d ;\
	fit f(x) "A.txt" using 1:3 via a,b ;\
	fit g(x) "B.txt" using 1:3 via c,d ;\
	plot \
	"A.txt" using 1:3 with points title "A error "\
	,"B.txt" using 1:3 with points title "B error"\
	, f(x) with lines title sprintf("%3.1f*n^{%3.1f}",a,b)\
	, g(x) with lines title sprintf("%3.1f*n^{%3.1f}",c,d)\
	' |gnuplot
	
ErrorError.gnuplot.png: main Makefile AA.txt BB.txt out.txt
	echo '\
	set terminal png;\
	set output "$@";\
	set key top left;\
	set tics out;\
	set xlabel "N";\
	set ylabel "error";\
	set title "error comparision";\
	e=1; f=-0.5; i(x)=e*x**f ;\
	g=1; h=-0.2; j(x)=g*x**h ;\
	fit i(x) "AA.txt" using 1:3 via e,f ;\
	fit j(x) "BB.txt" using 1:3 via g,h ;\
	plot \
	"AA.txt" using 1:3 with points title "A error "\
	,"BB.txt" using 1:3 with points title "B error"\
	, i(x) with lines title sprintf("%3.1f*n^{%3.1f}",e,f)\
	, j(x) with lines title sprintf("%3.1f*n^{%3.1f}",g,h)\
	' |gnuplot

A.txt:main

B.txt:main

AA.txt:main

BB.txt:main

out.txt: main 
	./$< > $@
    
main: functions.c main.c 
    
clean: 
	$(RM) main main.o functions.o *.txt *.png *.gpi