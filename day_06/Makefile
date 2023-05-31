.PHONY: all
all: day_06

day_06: day_06.o
	gcc -o $@ $^

%.o: %.c
	gcc -c $< -o $@

.PHONY: clean
clean:
	rm -f day_06 *.o
