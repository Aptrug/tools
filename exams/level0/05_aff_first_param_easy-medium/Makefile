NAME		= aff_first_param
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
		$(BIN) vincent mit "l'ane" dans un pre et "s'en" vint; \
		$(BIN) "j'aime le fromage de chevre"; \
		$(BIN); \
	} | cat -e)
	EXPECTED=$$(printf 'vincent$$\nj'"'"'aime le fromage de chevre$$\n$$')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: aff_first_param output mismatch"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) || exit 1
	fi
	echo "PASS: aff_first_param"

clean:
	rm -rf $(BUILD_DIR)
