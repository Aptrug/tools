NAME		= tab_mult
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
	ACTUAL=$$($(BIN) 9)
	EXPECTED=$$(printf '1 x 9 = 9\n2 x 9 = 18\n3 x 9 = 27\n4 x 9 = 36\n5 x 9 = 45\n6 x 9 = 54\n7 x 9 = 63\n8 x 9 = 72\n9 x 9 = 81')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: tab_mult output mismatch (9)"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	ACTUAL=$$($(BIN) 19)
	EXPECTED=$$(printf '1 x 19 = 19\n2 x 19 = 38\n3 x 19 = 57\n4 x 19 = 76\n5 x 19 = 95\n6 x 19 = 114\n7 x 19 = 133\n8 x 19 = 152\n9 x 19 = 171')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: tab_mult output mismatch (19)"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	ACTUAL=$$($(BIN) | cat -e)
	EXPECTED=$$(printf '$$')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: tab_mult output mismatch (no args)"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) || exit 1
	fi
	echo "PASS: tab_mult"

clean:
	rm -rf $(BUILD_DIR)
