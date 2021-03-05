CFLAGS = -Wall -O1 -std=gnu11
LDLIBS = -lm

exp.pdf: ms.tex fig-exp-pyxplot.pdf
	pdflatex $<
	pdflatex $<

out.data.txt:main
	./$< > $@

main:main.o myexp.o


fig-exp-pyxplot.pdf: fig-exp-pyxplot.gpi out.data.txt
	pyxplot $<
