.PHONY: all
all: day_05

day_05: day_05.o
	gcc -o $@ $^

%.o: %.c
	gcc -c $< -o $@

.PHONY: clean
clean:
	rm -f day_05 *.o
