.PHONY: all
all: day_03

day_03: day_03.o
	gcc -o $@ $^

%.o: %.c
	gcc -c $< -o $@

.PHONY: clean
clean:
	rm -f day_03 *.o
