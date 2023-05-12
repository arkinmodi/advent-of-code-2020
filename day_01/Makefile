.PHONY: all
all: day_01

day_01: day_01.o
	gcc -o day_01 day_01.o

day_01.o: day_01.c
	gcc -c day_01.c -o day_01.o

.PHONY: clean
clean:
	rm -f day_01 day_01.o
