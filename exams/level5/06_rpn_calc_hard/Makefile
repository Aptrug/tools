NAME		= rpn_calc
SRC		= rpn_calc.c

CC		:= $(shell command -v clang 2>/dev/null || echo cc)
CFLAGS		= -ansi -pedantic-errors -Wall -Wextra -Werror -pipe

BUILD_DIR	= .build
BIN		= $(BUILD_DIR)/test_$(NAME)

.ONESHELL:

.PHONY: test clean

# if command -v norminette >/dev/null 2>&1; then
# 	norminette -R CheckForbiddenSourceHeader $(SRC) rpn_calc.h || exit 1
# fi
test:
	set -e
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -I. $(SRC) -o $(BIN)
	ACTUAL=$$( { \
		$(BIN) "1 2 * 3 * 4 +"; \
		$(BIN) "1 2 3 4 +"; \
		$(BIN); \
		$(BIN) "3 4 +"; \
		$(BIN) "5 10 9 / - 50 *"; \
		$(BIN) "10 0 /"; \
		$(BIN) "10 0 %"; \
		$(BIN) "abc"; \
		$(BIN) "5"; \
		$(BIN) "-5 3 +"; \
		$(BIN) "3 -5 +"; \
		$(BIN) "3 4 + 5"; \
		$(BIN) ""; \
		$(BIN) "   "; \
		$(BIN) "3 4 ++"; \
		$(BIN) "3 4 -"; \
		$(BIN) "4 3 -"; \
	} | cat -e)
	EXPECTED=$$(printf '10$$\nError$$\nError$$\n7$$\n200$$\nError$$\nError$$\nError$$\n5$$\n-2$$\n-2$$\nError$$\nError$$\nError$$\nError$$\n-1$$\n1$$')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: rpn_calc output mismatch"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	echo "PASS: rpn_calc"

clean:
	rm -rf $(BUILD_DIR)
