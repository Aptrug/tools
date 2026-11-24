NAME		= camel_to_snake
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
		$(BIN) "hereIsACamelCaseWord"; \
		$(BIN) "helloWorld"; \
		$(BIN); \
	} | cat -e)
	EXPECTED=$$(printf 'here_is_a_camel_case_word$$\nhello_world$$\n$$')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: camel_to_snake output mismatch"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) || exit 1
	fi
	echo "PASS: camel_to_snake"

clean:
	rm -rf $(BUILD_DIR)
