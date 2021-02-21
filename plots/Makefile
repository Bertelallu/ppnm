CFLAGS = $(shell gsl-config --cflags)
LDLIBS = $(shell gsl-config --libs)

all: Errorfunktion.pyxplot.png Gammafunktion.pyxplot.png

Errorfunktion.pyxplot.png: data.erf.txt tab.data.erf.txt Makefile
	echo '\
	set terminal png;\
	set output "$@";\
	set key top left;\
	set title "Error function of different types";\
	plot \
	"tab.data.erf.txt" using 1:2 with points title "tabulated data"\
	,"$<" using 1:2 with line title "wiki approximation"\
	,"$<" using 1:3 with line title "from math.h"\
	,"$<" using 1:4 with line title "from gsl-sf"\
	'| pyxplot

Gammafunktion.pyxplot.png: data.gam.txt tab.data.gam.txt Makefile
	echo '\
	set terminal png;\
	set output "$@";\
	set key top left;\
	set title "Error function of different types";\
	plot \
	"tab.data.gam.txt" using 1:2 with points title "tabulated data"\
	,"$<" using 1:2 with line title "wiki approximation"\
	,"$<" using 1:3 with line title "from math.h"\
	,"$<" using 1:4 with line title "from gsl-sf"\
	'| pyxplot

data.erf.txt: mainerf
	./$< > $@

data.gam.txt: maingam
	./$< > $@

mainerf: mainerf.o Erf.o

maingam: maingam.o Gam.o

clean:
	$(RM) *.o mainerf maingam data.txt 
