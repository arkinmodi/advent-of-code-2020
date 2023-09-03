DEPS_SRC := ../common/IntList.c
DEPS := $(patsubst %.c, %.o, $(DEPS_SRC))

.PHONY: all
all: day_01

.NOTPARALLEL: test
.PHONY: test
test: day_01.o $(DEPS) day_01_test.o
	clang -e _test -o $@ $^
	./test

day_01: day_01.o $(DEPS)
	clang -o $@ $^

%.o: %.c
	clang -c $< -o $@

.PHONY: clean
clean:
	rm -f day_01 test *.o
