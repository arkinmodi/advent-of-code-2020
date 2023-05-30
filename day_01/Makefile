.PHONY: all
all: day_01

day_01: day_01.o
	gcc -o $@ $^

%.o: %.c
	gcc -c $< -o $@

.PHONY: clean
clean:
	rm -f day_01 *.o
