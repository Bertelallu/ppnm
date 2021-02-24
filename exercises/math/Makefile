CC = gcc
CFLAGS = -std=gnu99 -O -Wall
LDLIBS = -lm

answers.txt: exercise
	./exercise > answers.txt

exercise:exercise.o
	$(CC) $(LDFLAGS) $< -o $@ $(LDLIBS)

exercise.o:exercise.c
	$(CC) $(CFLAGS) -c exercise.c -o exercise.o
clean:
	$(RM) exercise *.o answers* 

