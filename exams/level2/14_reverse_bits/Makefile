NAME		= reverse_bits
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

	unsigned char reverse_bits(unsigned char octet);

	void print_bin(unsigned char c)
	{
		int	i;

		i = 7;
		while (i >= 0)
		{
			putchar('0' + ((c >> i) & 1));
			i--;
		}
	}

	int main(void)
	{
		print_bin(reverse_bits(0x26));
		printf("\n");
		print_bin(reverse_bits(0));
		printf("\n");
		print_bin(reverse_bits(255));
		printf("\n");
		print_bin(reverse_bits(1));
		printf("\n");
		return (0);
	}
	EOF
	$(CC) $(CFLAGS) $(SRC) $(BUILD_DIR)/main.c -o $(BIN)
	ACTUAL=$$($(BIN))
	EXPECTED=$$(printf '01100100\n00000000\n11111111\n10000000')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: reverse_bits output mismatch"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) || exit 1
	fi
	echo "PASS: reverse_bits"

clean:
	rm -rf $(BUILD_DIR)
