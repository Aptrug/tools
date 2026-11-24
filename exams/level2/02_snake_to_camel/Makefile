NAME		= snake_to_camel
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
		$(BIN) "here_is_a_snake_case_word"; \
		$(BIN) "hello_world"; \
		$(BIN); \
	} | cat -e)
	EXPECTED=$$(printf 'hereIsASnakeCaseWord$$\nhelloWorld$$\n$$')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: snake_to_camel output mismatch"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) || exit 1
	fi
	echo "PASS: snake_to_camel"

clean:
	rm -rf $(BUILD_DIR)
