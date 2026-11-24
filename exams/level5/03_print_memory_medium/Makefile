NAME		= print_memory
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
	#include <stddef.h>
	void print_memory(const void *addr, size_t size);

	int main(void)
	{
		int tab[10] = {0, 23, 150, 255, 12, 16, 21, 42};
		char buf[3];
		buf[0] = 'A';
		buf[1] = 'B';
		buf[2] = 'C';

		print_memory(tab, sizeof(tab));
		print_memory(buf, 0);
		print_memory(buf, 3);
		print_memory("Hello, World!", 13);
		return (0);
	}
	EOF
	$(CC) $(CFLAGS) $(SRC) $(BUILD_DIR)/main.c -o $(BIN)
	ACTUAL=$$($(BIN) | cat -e)
	EXPECTED=$$(printf '0000 0000 1700 0000 9600 0000 ff00 0000 ................$$\n0c00 0000 1000 0000 1500 0000 2a00 0000 ............*...$$\n0000 0000 0000 0000                     ........$$\n4142 43                                 ABC$$\n4865 6c6c 6f2c 2057 6f72 6c64 21        Hello, World!$$')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: print_memory output mismatch"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) || exit 1
	fi
	echo "PASS: print_memory"

clean:
	rm -rf $(BUILD_DIR)
