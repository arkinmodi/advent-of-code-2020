DEPS_SRC := ../common/CharList.c
DEPS := $(patsubst %.c, %.o, $(DEPS_SRC))

.PHONY: all
all: day_05

.NOTPARALLEL: test
.PHONY: test
test: day_05.o $(DEPS) day_05_test.o
	clang -e _test -o $@ $^
	./test

day_05: day_05.o $(DEPS)
	clang -o $@ $^

%.o: %.c
	clang -c $< -o $@

.PHONY: clean
clean:
	rm -f day_05 test *.o
