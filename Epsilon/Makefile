CC = clang
CFLAGS = -std=gnu11
CFLAGS += -Wall
LDFLAGS = -I.
LDLIBS = -lm

out.txt: eps
	./$< > $@

clean:
	$(RM) eps out.txt

