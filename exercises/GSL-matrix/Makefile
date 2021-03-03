CFLAGS = -Wall -O1 -std=gnu11
CFLAGS += $(shell /usr/bin/gsl-config --cflags)
LDLIBS += $(shell /usr/bin/gsl-config --libs)

.PHONEY:all
all:main

.PHONEY:clean
clean:
	$(RM) main

test:
	@echo $(CFLAGS)
	@echo $(LDLIBS)
