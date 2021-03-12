CFLAGS=-Wall -Werror -O1
CFLAGS+=$(shell gsl-config --cflags)
LDLIBS+=$(shell gsl-config --libs)
CC=gcc

.PHONEY:default
default:main fig-linterp-pyxplot.png

main: main.c linterp.c linterp_integ.c binsearch.c

fig-linterp-pyxplot.png: fig-linterp-pyxplot.gpi linterp.dat
	pyxplot $<

linterp.dat: main
	./main

main.c: input.dat

#fig-linterp-integ-pyxplot.pdf: fig-linterp-integ-pyxplot.gpi linterp.dat
#	pyxplot $<



