NAME		= brackets
SRC		= $(NAME).c

CC		:= $(shell command -v clang 2>/dev/null || echo cc)
CFLAGS		= -ansi -pedantic-errors -Wall -Wextra -Werror -pipe

BUILD_DIR	= .build
BIN		= $(BUILD_DIR)/test_$(NAME)

.ONESHELL:

.PHONY: test clean

# if command -v norminette >/dev/null 2>&1; then
# 	norminette -R CheckForbiddenSourceHeader $(SRC) || exit 1
# fi
test:
	set -e
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -I. $(SRC) -o $(BIN)
	ACTUAL=$$( { \
		$(BIN) '(johndoe)'; \
		$(BIN) '([)]'; \
		$(BIN) '' '{[(0 + 0)(1 + 1)](3*(-1)){()}}'; \
		$(BIN); \
		$(BIN) '('; \
		$(BIN) ')'; \
		$(BIN) 'no brackets here'; \
		$(BIN) '[{(})]'; \
	} | cat -e)
	EXPECTED=$$(printf 'OK$$\nError$$\nOK$$\nOK$$\n$$\nError$$\nError$$\nOK$$\nError$$')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: brackets output mismatch"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	echo "PASS: brackets"

clean:
	rm -rf $(BUILD_DIR)
