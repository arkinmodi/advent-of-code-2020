DEPS_SRC := ../common/CharList.c
DEPS := $(patsubst %.c, %.o, $(DEPS_SRC))

.PHONY: all
all: day_04

.NOTPARALLEL: test
.PHONY: test
test: day_04.o $(DEPS) day_04_test.o
	gcc -e _test -o $@ $^
	./test

day_04: day_04.o $(DEPS)
	gcc -o $@ $^

%.o: %.c
	gcc -c $< -o $@

.PHONY: clean
clean:
	rm -f day_04 test *.o
