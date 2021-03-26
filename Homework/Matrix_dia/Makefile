CFLAGS = -Wall -O1 -std=gnu11 #-DNDEBUG
CFLAGS += $(shell /usr/bin/gsl-config --cflags)
LDLIBS += $(shell /usr/bin/gsl-config --libs)
CC = gcc

default: partyinabox.pyxplot.png timediagonalization.pyxplot.png out.txt

partyinabox.pyxplot.png: main eigenfunctions.txt Makefile out.txt
	echo '\
	set terminal png;\
	set output "$@";\
	set key top left;\
	set tics out;\
	set xlabel "N";\
	set ylabel "Time (s)";\
	set title "Our function";\
	plot \
	"eigenfunctions.txt" using 1:2 with line title "n=1 eigenfunction"\
	,"eigenfunctions.txt" using 1:3 with line title "n=2 eigenfunction"\
	,"eigenfunctions.txt" using 1:4 with line title "n=3 eigenfunction"\
	,"exacteigenfunctions.txt" using 1:2 with line title "n=1 exact eigenfunction"\
	,"exacteigenfunctions.txt" using 1:3 with line title "n=2 exact eigenfunction"\
	,"exacteigenfunctions.txt" using 1:4 with line title "n=3 exact eigenfunction"\
	' | tee tmp.gpi | pyxplot

timediagonalization.pyxplot.png: main Makefile
	echo '\
	set terminal png;\
	set output "$@";\
	set key top left;\
	set tics out;\
	set xlabel "N";\
	set ylabel "Time (s)";\
	set title "Our function";\
	plot \
	"out_time_jacobi.txt" using 1:2 with line title "Our implementation"\
	,"out_time_gsl.txt" using 1:2 with line title "GSL"\
	,"out_time_jacobiop.txt" using 1:2 with line title "Our optimized implementation"\
	' | tee tmp.gpi | pyxplot

#out_time_jacobi.txt: main functions.o
#
#out_time_gsl.txt: main functions.o

eigenfunctions.txt: main

out.txt: main 
	./$< > $@

main: main.o functions.o

#main.o: main.c
#
#functions.o: functions.c

