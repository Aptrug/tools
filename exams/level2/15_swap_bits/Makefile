NAME		= swap_bits
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

	unsigned char swap_bits(unsigned char octet);

	int main(void)
	{
		printf("%02x\n", swap_bits(0x41));
		printf("%02x\n", swap_bits(0x00));
		printf("%02x\n", swap_bits(0xff));
		printf("%02x\n", swap_bits(0x12));
		return (0);
	}
	EOF
	$(CC) $(CFLAGS) $(SRC) $(BUILD_DIR)/main.c -o $(BIN)
	ACTUAL=$$($(BIN))
	EXPECTED=$$(printf '14\n00\nff\n21')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: swap_bits output mismatch"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) || exit 1
	fi
	echo "PASS: swap_bits"

clean:
	rm -rf $(BUILD_DIR)
