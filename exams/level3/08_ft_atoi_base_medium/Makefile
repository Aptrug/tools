NAME		= ft_atoi_base
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
	int ft_atoi_base(const char *str, int str_base);

	int main(void)
	{
		printf("%d\n", ft_atoi_base("101", 2));
		printf("%d\n", ft_atoi_base("12fdb3", 16));
		printf("%d\n", ft_atoi_base("12FDB3", 16));
		printf("%d\n", ft_atoi_base("-2a", 16));
		printf("%d\n", ft_atoi_base("0123", 4));
		printf("%d\n", ft_atoi_base("0", 10));
		printf("%d\n", ft_atoi_base("-0", 10));
		return (0);
	}
	EOF
	$(CC) $(CFLAGS) $(SRC) $(BUILD_DIR)/main.c -o $(BIN)
	ACTUAL=$$($(BIN))
	EXPECTED=$$(printf '5\n1244595\n1244595\n-42\n27\n0\n0')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: ft_atoi_base output mismatch"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) || exit 1
	fi
	echo "PASS: ft_atoi_base"

clean:
	rm -rf $(BUILD_DIR)
