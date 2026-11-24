NAME		= fizzbuzz
SRC		= $(NAME).c

CC		:= $(shell command -v clang 2>/dev/null || echo cc)
CFLAGS		= -ansi -pedantic-errors -Wall -Wextra -Werror -pipe

BUILD_DIR	= .build
BIN		= $(BUILD_DIR)/test_$(NAME)

.ONESHELL:

.PHONY: test clean

test:
	set -e
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(SRC) -o $(BIN)
	ACTUAL=$$($(BIN))
	LINES=$$(echo "$$ACTUAL" | wc -l)
	if [ "$$LINES" != "100" ]; then
		echo "FAIL: fizzbuzz expected 100 lines, got $$LINES"
		exit 1
	fi
	HEAD=$$(echo "$$ACTUAL" | head -15)
	EXPECTED_HEAD=$$(printf '1\n2\nfizz\n4\nbuzz\nfizz\n7\n8\nfizz\nbuzz\n11\nfizz\n13\n14\nfizzbuzz')
	if [ "$$HEAD" != "$$EXPECTED_HEAD" ]; then
		echo "FAIL: fizzbuzz output mismatch (head)"
		echo "  expected: $$EXPECTED_HEAD"
		echo "  actual:   $$HEAD"
		exit 1
	fi
	TAIL=$$(echo "$$ACTUAL" | tail -4)
	EXPECTED_TAIL=$$(printf '97\n98\nfizz\nbuzz')
	if [ "$$TAIL" != "$$EXPECTED_TAIL" ]; then
		echo "FAIL: fizzbuzz output mismatch (tail)"
		echo "  expected: $$EXPECTED_TAIL"
		echo "  actual:   $$TAIL"
		exit 1
	fi
	L33=$$(echo "$$ACTUAL" | sed -n '33p')
	L45=$$(echo "$$ACTUAL" | sed -n '45p')
	L15=$$(echo "$$ACTUAL" | sed -n '15p')
	if [ "$$L33" != "fizz" ] || [ "$$L45" != "fizzbuzz" ] || [ "$$L15" != "fizzbuzz" ]; then
		echo "FAIL: fizzbuzz multiple-of-15 lines are wrong"
		exit 1
	fi
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) || exit 1
	fi
	echo "PASS: fizzbuzz"

clean:
	rm -rf $(BUILD_DIR)
