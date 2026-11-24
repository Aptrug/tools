NAME		= rot_13
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
	ACTUAL=$$( { \
		$(BIN) "abc"; \
		$(BIN) "My horse is Amazing."; \
		$(BIN) "AkjhZ zLKIJz , 23y "; \
		$(BIN); \
		$(BIN) ""; \
	} | cat -e)
	EXPECTED=$$(printf 'nop$$\nZl ubefr vf Nznmvat.$$\nNxwuM mYXVWm , 23l $$\n$$\n$$')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: rot_13 output mismatch"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) || exit 1
	fi
	echo "PASS: rot_13"

clean:
	rm -rf $(BUILD_DIR)
