NAME		= brainfuck
SRC		= brainfuck.c

CC		:= $(shell command -v clang 2>/dev/null || echo cc)
CFLAGS		= -ansi -pedantic-errors -Wall -Wextra -Werror -pipe

BUILD_DIR	= .build
BIN		= $(BUILD_DIR)/test_$(NAME)

.ONESHELL:

.PHONY: test clean

# if command -v norminette >/dev/null 2>&1; then
# 	norminette -R CheckForbiddenSourceHeader $(SRC) brainfuck.h || exit 1
# fi
test:
	set -e
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -I. $(SRC) -o $(BIN)
	HELLO=$$(printf '++++++++++[>+++++++>++++++++++>+++>+<<<<-]\n>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.')
	ACTUAL=$$( { \
		$(BIN) "$$HELLO"; \
		$(BIN) "+++++[>++++[>++++H>+++++i<<-]>>>++\n<<<<-]>>--------.>+++++.>."; \
		$(BIN); \
	} | cat -e)
	EXPECTED=$$(printf 'Hello World!$$\nHi$$\n$$')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: brainfuck output mismatch"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	echo "PASS: brainfuck"

clean:
	rm -rf $(BUILD_DIR)
