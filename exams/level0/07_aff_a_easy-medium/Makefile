NAME		= aff_a
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
		$(BIN) "dubO a POIL"; \
		$(BIN) "zz sent le poney"; \
		$(BIN); \
		$(BIN) "one" "two"; \
	} | cat -e)
	EXPECTED=$$(printf 'a$$\na$$\n$$\na$$\na$$')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: aff_a output mismatch"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) || exit 1
	fi
	echo "PASS: aff_a"

clean:
	rm -rf $(BUILD_DIR)
