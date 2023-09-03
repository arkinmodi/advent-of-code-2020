DEPS_SRC := ../common/CharList.c
DEPS := $(patsubst %.c, %.o, $(DEPS_SRC))

.PHONY: all
all: day_06

.NOTPARALLEL: test
.PHONY: test
test: day_06.o $(DEPS) day_06_test.o
	gcc -e _test -o $@ $^
	./test

day_06: day_06.o $(DEPS)
	gcc -o $@ $^

%.o: %.c
	gcc -c $< -o $@

.PHONY: clean
clean:
	rm -f day_06 test *.o
