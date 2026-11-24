NAME		= print_bits
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
	#include <unistd.h>

	void print_bits(unsigned char octet);

	int main(void)
	{
		print_bits(2);
		write(1, "\n", 1);
		print_bits(255);
		write(1, "\n", 1);
		print_bits(0);
		write(1, "\n", 1);
		print_bits(128);
		write(1, "\n", 1);
		return (0);
	}
	EOF
	$(CC) $(CFLAGS) $(SRC) $(BUILD_DIR)/main.c -o $(BIN)
	ACTUAL=$$($(BIN))
	EXPECTED=$$(printf '00000010\n11111111\n00000000\n10000000')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: print_bits output mismatch"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) || exit 1
	fi
	echo "PASS: print_bits"

clean:
	rm -rf $(BUILD_DIR)
