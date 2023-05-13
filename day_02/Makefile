.PHONY: all
all: day_02

day_02: day_02.o
	gcc -o day_02 day_02.o

day_02.o: day_02.c
	gcc -c day_02.c -o day_02.o

.PHONY: clean
clean:
	rm -f day_02 day_02.o
