NAME		= ft_strcpy
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
	char *ft_strcpy(char *s1, char *s2);

	int main(void)
	{
		char	dest[64];
		char	*ret;

		ret = ft_strcpy(dest, "Hello, World!");
		printf("%s\n", dest);
		printf("%d\n", ret == dest);
		ft_strcpy(dest, "");
		printf("[%s]\n", dest);
		ft_strcpy(dest, "42");
		printf("%s\n", dest);
		return (0);
	}
	EOF
	$(CC) $(CFLAGS) $(SRC) $(BUILD_DIR)/main.c -o $(BIN)
	ACTUAL=$$($(BIN))
	EXPECTED=$$(printf 'Hello, World!\n1\n[]\n42')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: ft_strcpy output mismatch"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) || exit 1
	fi
	echo "PASS: ft_strcpy"

clean:
	rm -rf $(BUILD_DIR)
