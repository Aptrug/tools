NAME		= paramsum
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
		$(BIN) 1 2 3 5 7 24; \
		$(BIN) 6 12 24; \
		$(BIN); \
	} | cat -e)
	EXPECTED=$$(printf '6$$\n3$$\n0$$')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: paramsum output mismatch"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) || exit 1
	fi
	echo "PASS: paramsum"

clean:
	rm -rf $(BUILD_DIR)
