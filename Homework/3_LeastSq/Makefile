CFLAGS = -Wall -O1 -std=gnu11 #-DNDEBUG
CFLAGS += $(shell /usr/bin/gsl-config --cflags)
LDLIBS += $(shell /usr/bin/gsl-config --libs)
CC = gcc

default: least.pyxplot.png out.txt

least.pyxplot.png: datafile.txt data.txt Makefile out.txt
	echo '\
	set terminal png;\
	set output "$@";\
	set key top right;\
	set tics out;\
	set xlabel "Time (days)";\
	set ylabel "ln(Activity)";\
	set title "Least squares fit";\
	plot \
	"datafile.txt" using 1:2 with lines title "Our fit"\
	,"datafile.txt" using 1:3 with lines title "Our fit (+δck)"\
	,"datafile.txt" using 1:4 with lines title "Our fit (-δck)"\
    ,"data.txt" using 1:4:5 with yerrorbars title "Data with errorbars"\
	' | tee tmp.gpi | pyxplot

out.txt: main 
	./$< > $@

datafile.txt: main

main: main.c functions.c
    
clean: 
	$(RM) main *.o out.txt least.pyxplot.png datafile.txt tmp.gpi