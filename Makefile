AOC_DAYS := $(shell find . -maxdepth 1 -type d -name 'day_*')
COMMON_DEPS_DIR := common
COMMON_DEPS_SRC := $(shell find $(COMMON_DEPS_DIR) -maxdepth 1 -type f -name '*.c')
COMMON_DEPS := $(patsubst %.c, %.o, $(COMMON_DEPS_SRC))

.PHONY: all
all: $(AOC_DAYS)

%.o: %.c
	gcc -c $< -o $@

.PHONY: $(AOC_DAYS)
$(AOC_DAYS): $(COMMON_DEPS)
	make -C $@

.PHONY: test
test:
	for day in $(AOC_DAYS); do make -C $$day test || exit 1; done

.NOTPARALLEL: run-test
.PHONY: run-test
run-test:
	for day in $(AOC_DAYS); do make -C $$day run-test || exit 1; done

.PHONY: lint
lint:
	clang-format --Werror -i $$(git ls-files -- '*.c') $$(git ls-files -- '*.h')

.PHONY: clean
clean:
	rm -f $(COMMON_DEPS_DIR)/*.o
	for day in $(AOC_DAYS); do make -C $$day clean || exit 1; done
