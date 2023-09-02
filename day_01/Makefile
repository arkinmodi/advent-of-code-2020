.PHONY: all
all: day_01

.PHONY: test
test: day_01.o day_01_test.o
	gcc -e _test -o $@ $^
	./test

day_01: day_01.o
	gcc -o $@ $^

%.o: %.c
	gcc -c $< -o $@

.PHONY: clean
clean:
	rm -f day_01 test *.o
