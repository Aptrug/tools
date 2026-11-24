NAME		= rev_wstr
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
		$(BIN) "You hate people! But I love gatherings. Isn't it ironic?"; \
		$(BIN) "abcdefghijklm"; \
		$(BIN) "Wingardium Leviosa"; \
		$(BIN); \
		$(BIN) "a" "b"; \
	} | cat -e)
	EXPECTED=$$(printf "ironic? it Isn't gatherings. love I But people! hate You\$$\nabcdefghijklm\$$\nLeviosa Wingardium\$$\n\$$\n\$$")
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: rev_wstr output mismatch"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) || exit 1
	fi
	echo "PASS: rev_wstr"

clean:
	rm -rf $(BUILD_DIR)
