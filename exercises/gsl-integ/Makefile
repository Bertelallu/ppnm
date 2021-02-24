CFLAGS=-Wall -Werror -O1
CFLAGS+=$(shell gsl-config --cflags)
LDLIBS+=$(shell gsl-config --libs)
CC=gcc


.PHONEY:default
default:main errorfunction.png besselfunction.png


besselfunction.png: out.besselfunction.txt Makefile
	echo '\
	set terminal png;\
	set output "$@";\
	set key top left;\
	set title "Besselfunction of different types";\
	plot \
	 "$<" using 1:2 with line title "n=0"\
	,"$<" using 1:3 with line title "n=1"\
	,"$<" using 1:4 with line title "n=2"\
	,"$<" using 1:5 with line title "n=3"\
	,"$<" using 1:6 with line title "n=4"\
	,"$<" using 1:7 with line title "n=5"\'|pyxplot


errorfunction.png: out.errorfunction.txt Makefile
	echo '\
	set terminal png;\
	set output "$@";\
	set key top left;\
	set title "errorfunction of different types";\
	plot \
	 "$<" using 1:2 with line title "errorfunction"\'|pyxplot

out.errorfunction.txt: errorfunction
	./$< > $@

out.besselfunction.txt:besselfunction
	./$< > $@

clean:
	$(RM) main out* errorfunction besselfunction


