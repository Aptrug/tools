NAME		= options
SRC		= options.c

CC		:= $(shell command -v clang 2>/dev/null || echo cc)
CFLAGS		= -ansi -pedantic-errors -Wall -Wextra -Werror -pipe

BUILD_DIR	= .build
BIN		= $(BUILD_DIR)/test_$(NAME)

.ONESHELL:

.PHONY: test clean

# if command -v norminette >/dev/null 2>&1; then
# 	norminette -R CheckForbiddenSourceHeader $(SRC) options.h || exit 1
# fi
test:
	set -e
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -I. $(SRC) -o $(BIN)
	ACTUAL=$$( { \
		$(BIN); \
		$(BIN) -abc -ijk; \
		$(BIN) -z; \
		$(BIN) -abc -hijk; \
		$(BIN) -%; \
		$(BIN) -h; \
		$(BIN) -a -a; \
		$(BIN) notanoption; \
	} | cat -e)
	EXPECTED=$$(printf 'options: abcdefghijklmnopqrstuvwxyz$$\n1799$$\n33554432$$\noptions: abcdefghijklmnopqrstuvwxyz$$\nInvalid Option$$\noptions: abcdefghijklmnopqrstuvwxyz$$\n1$$\nInvalid Option$$')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: options output mismatch"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	echo "PASS: options"

clean:
	rm -rf $(BUILD_DIR)
