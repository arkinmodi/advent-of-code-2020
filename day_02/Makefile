.PHONY: all
all: day_02

day_02: day_02.o
	gcc -o $@ $^

%.o: %.c
	gcc -c $< -o $@

.PHONY: clean
clean:
	rm -f day_02 *.o
