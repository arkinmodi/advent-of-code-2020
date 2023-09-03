CC := gcc
CFLAGS := -g -O2 -Wall -Wextra -Werror -pg -std=c99

DEPS_SRC := ../common/CharList.c
DEPS := $(patsubst %.c, %.o, $(DEPS_SRC))

.PHONY: all
all: day_06

.NOTPARALLEL: run-test
.PHONY: run-test
run-test: test
	./test

test: day_06.o $(DEPS) day_06_test.o
	$(CC) $(CFLAGS) -o $@ $^

day_06: day_06.o $(DEPS) day_06_cli.o
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f day_06 test *.o
