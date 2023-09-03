DEPS_SRC := ../common/CharList.c
DEPS := $(patsubst %.c, %.o, $(DEPS_SRC))

.PHONY: all
all: day_03

.NOTPARALLEL: test
.PHONY: test
test: day_03.o $(DEPS) day_03_test.o
	gcc -e _test -o $@ $^
	./test

day_03: day_03.o $(DEPS)
	gcc -o $@ $^

%.o: %.c
	gcc -c $< -o $@

.PHONY: clean
clean:
	rm -f day_03 test *.o
