.PHONY: all
all: day_04

day_04: day_04.o
	gcc -o $@ $^

%.o: %.c
	gcc -c $< -o $@

.PHONY: clean
clean:
	rm -f day_04 *.o
