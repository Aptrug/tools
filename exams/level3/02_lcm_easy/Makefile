NAME		= lcm
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
	cat > $(BUILD_DIR)/main.c << 'EOF'
	#include <stdio.h>
	unsigned int lcm(unsigned int a, unsigned int b);

	int main(void)
	{
		printf("%u\n", lcm(4, 6));
		printf("%u\n", lcm(21, 6));
		printf("%u\n", lcm(3, 5));
		printf("%u\n", lcm(0, 5));
		printf("%u\n", lcm(5, 0));
		printf("%u\n", lcm(7, 7));
		return (0);
	}
	EOF
	$(CC) $(CFLAGS) $(SRC) $(BUILD_DIR)/main.c -o $(BIN)
	ACTUAL=$$($(BIN))
	EXPECTED=$$(printf '12\n42\n15\n0\n0\n7')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: lcm output mismatch"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) || exit 1
	fi
	echo "PASS: lcm"

clean:
	rm -rf $(BUILD_DIR)
