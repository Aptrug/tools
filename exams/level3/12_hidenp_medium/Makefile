NAME		= hidenp
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
		$(BIN) "fgex.;" "tyf34gdgf;'ektufjhgdgex.;.;rtjynur6"; \
		$(BIN) "abc" "2altrb53c.sse"; \
		$(BIN) "abc" "btarc"; \
		$(BIN); \
	} | cat -e)
	EXPECTED=$$(printf '1$$\n1$$\n0$$\n$$')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: hidenp output mismatch"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) || exit 1
	fi
	echo "PASS: hidenp"

clean:
	rm -rf $(BUILD_DIR)
