.PHONY: all
all: day_03

day_03: day_03.o
	gcc -o day_03 day_03.o

day_03.o: day_03.c
	gcc -c day_03.c -o day_03.o

.PHONY: clean
clean:
	rm -f day_03 day_03.o
