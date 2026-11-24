NAME		= checkmate
SRC		= checkmate.c

CC		:= $(shell command -v clang 2>/dev/null || echo cc)
CFLAGS		= -ansi -pedantic-errors -Wall -Wextra -Werror -pipe

BUILD_DIR	= .build
BIN		= $(BUILD_DIR)/test_$(NAME)

.ONESHELL:

.PHONY: test clean

# if command -v norminette >/dev/null 2>&1; then
# 	norminette -R CheckForbiddenSourceHeader $(SRC) checkmate.h || exit 1
# fi

test:
	set -e
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(SRC) -o $(BIN)
	ACTUAL=$$( { \
		$(BIN) '..' '.K'; \
		$(BIN) 'R...' '..P.' '.K..' '....'; \
		$(BIN) 'R...' 'iheK' '....' 'jeiR'; \
		$(BIN); \
	} | cat -e)
	EXPECTED=$$(printf 'Fail$$\nSuccess$$\nSuccess$$\n$$')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: checkmate output mismatch"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	echo "PASS: checkmate"

clean:
	rm -rf $(BUILD_DIR)
