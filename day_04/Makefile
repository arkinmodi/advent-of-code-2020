CC := gcc
CFLAGS := -g -O2 -Wall -Wextra -Werror -pg -std=c99

DEPS_SRC := ../common/CharList.c
DEPS := $(patsubst %.c, %.o, $(DEPS_SRC))

.PHONY: all
all: day_04

.NOTPARALLEL: run-test
.PHONY: run-test
run-test: test
	./test

test: day_04.o $(DEPS) day_04_test.o
	$(CC) $(CFLAGS) -o $@ $^

day_04: day_04.o $(DEPS) day_04_cli.o
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f day_04 test *.o
