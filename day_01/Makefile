CC := gcc
CFLAGS := -g -O2 -Wall -Wextra -Werror -pg -std=c99

DEPS_SRC := ../common/IntList.c
DEPS := $(patsubst %.c, %.o, $(DEPS_SRC))

.PHONY: all
all: day_01

.NOTPARALLEL: run-test
.PHONY: run-test
run-test: test
	./test

test: day_01.o $(DEPS) day_01_test.o
	$(CC) $(CFLAGS) -o $@ $^

day_01: day_01.o $(DEPS) day_01_cli.o
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f day_01 test *.o
