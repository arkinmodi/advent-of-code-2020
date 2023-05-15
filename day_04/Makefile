.PHONY: all
all: day_04

day_04: day_04.o
	gcc -o day_04 day_04.o

day_04.o: day_04.c
	gcc -c day_04.c -o day_04.o

.PHONY: clean
clean:
	rm -f day_04 day_04.o
