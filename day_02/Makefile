CC := gcc
CFLAGS := -g -O2 -Wall -Wextra -Werror -pg -std=c99

DEPS_SRC := ../common/CharList.c
DEPS := $(patsubst %.c, %.o, $(DEPS_SRC))

.PHONY: all
all: day_02

.NOTPARALLEL: run-test
.PHONY: run-test
run-test: test
	./test

test: day_02.o $(DEPS) day_02_test.o
	$(CC) $(CFLAGS) -o $@ $^

day_02: day_02.o $(DEPS) day_02_cli.o
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f day_02 test *.o
