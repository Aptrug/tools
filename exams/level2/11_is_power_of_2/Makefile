NAME		= is_power_of_2
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

	int is_power_of_2(unsigned int n);

	int main(void)
	{
		printf("%d\n", is_power_of_2(0));
		printf("%d\n", is_power_of_2(1));
		printf("%d\n", is_power_of_2(2));
		printf("%d\n", is_power_of_2(3));
		printf("%d\n", is_power_of_2(1024));
		printf("%d\n", is_power_of_2(1023));
		printf("%d\n", is_power_of_2(2147483648u));
		printf("%d\n", is_power_of_2(4294967295u));
		return (0);
	}
	EOF
	$(CC) $(CFLAGS) $(SRC) $(BUILD_DIR)/main.c -o $(BIN)
	ACTUAL=$$($(BIN))
	EXPECTED=$$(printf '0\n1\n1\n0\n1\n0\n1\n0')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: is_power_of_2 output mismatch"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) || exit 1
	fi
	echo "PASS: is_power_of_2"

clean:
	rm -rf $(BUILD_DIR)
