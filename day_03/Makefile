CC := gcc
CFLAGS := -g -O2 -Wall -Wextra -Werror -pg -std=c99

DEPS_SRC := ../common/CharList.c
DEPS := $(patsubst %.c, %.o, $(DEPS_SRC))

.PHONY: all
all: day_03

.NOTPARALLEL: run-test
.PHONY: run-test
run-test: test
	./test

test: day_03.o $(DEPS) day_03_test.o
	$(CC) $(CFLAGS) -o $@ $^

day_03: day_03.o $(DEPS) day_03_cli.o
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f day_03 test *.o
