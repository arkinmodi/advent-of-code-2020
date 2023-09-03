DEPS_SRC := ../common/CharList.c
DEPS := $(patsubst %.c, %.o, $(DEPS_SRC))

.PHONY: all
all: day_02

.NOTPARALLEL: test
.PHONY: test
test: day_02.o $(DEPS) day_02_test.o
	gcc -e _test -o $@ $^
	./test

day_02: day_02.o $(DEPS)
	gcc -o $@ $^

%.o: %.c
	gcc -c $< -o $@

.PHONY: clean
clean:
	rm -f day_02 test *.o
