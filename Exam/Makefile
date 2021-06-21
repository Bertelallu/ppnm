CFLAGS = -Wall -O1 -std=gnu11 #-DNDEBUG
CFLAGS += $(shell /usr/bin/gsl-config --cflags)
LDLIBS += $(shell /usr/bin/gsl-config --libs)
CC = gcc

default: out.txt complexplanef4.pyxplot.png complexplanef1.pyxplot.png complexplanef2.pyxplot.png complexplanef3.pyxplot.png 

complexplanef1.pyxplot.png: out.txt Makefile
	echo '\
	set sample grid 200x200;\
	set terminal png;\
	set output "$@";\
	set key bottom left;\
	set tics out;\
	set xlabel "Re";\
	set ylabel "Im";\
	set title "The complex plane of $$f(z)=z$$";\
	plot \
	"function1.txt" using 1:2:3 with colormap title ""\
	,"line1.txt" using 1:2 with lines title "integration line"\
	,"points1.txt" using 1:2 with points title "first 4 points used"\
	' | tee tmp.gpi | pyxplot

complexplanef2.pyxplot.png: out.txt Makefile
	echo '\
	set sample grid 200x200;\
	set terminal png;\
	set output "$@";\
	set key bottom left;\
	set tics out;\
	set xlabel "Re";\
	set ylabel "Im";\
	set title "The complex plane of $$f(z)=Re(z)^2+i*Im(z)$$";\
	plot \
	"function2.txt" using 1:2:3 with colormap title ""\
	,"line2.txt" using 1:2 with lines title "integration line"\
	,"points2.txt" using 1:2 with points title "first 4 points used"\
	' | tee tmp.gpi | pyxplot
	
complexplanef3.pyxplot.png: out.txt Makefile
	echo '\
	set sample grid 200x200;\
	set terminal png;\
	set output "$@";\
	set key bottom left;\
	set tics out;\
	set xlabel "Re";\
	set ylabel "Im";\
	set title "The complex plane of $$f(z)=Re(z)*2+i*Im(z)+1$$";\
	plot \
	"function3.txt" using 1:2:3 with colormap title ""\
	,"line3.txt" using 1:2 with lines title "integration line"\
	,"points3.txt" using 1:2 with points title "first 4 points used"\
	' | tee tmp.gpi | pyxplot
	
complexplanef4.pyxplot.png: out.txt Makefile
	echo '\
	set sample grid 200x200;\
	set terminal png;\
	set output "$@";\
	set key bottom left;\
	set tics out;\
	set xlabel "Re";\
	set ylabel "Im";\
	set title "The complex plane of $$f(z)=cos(Re(z))+i*sin(Im(z))$$";\
	plot \
	"function4.txt" using 1:2:3 with colormap title ""\
	,"line4.txt" using 1:2 with lines title "integration line"\
	,"points4.txt" using 1:2 with points title "first 4 points used"\
	' | tee tmp.gpi | pyxplot

out.txt: main 
	./$< > $@
    
main: main.c functions.c 
    
clean: 
	$(RM) main main.o functions.o points.txt function*.txt out.txt *.png *.gpi line*.txt points*.txt