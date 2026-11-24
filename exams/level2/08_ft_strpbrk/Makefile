NAME		= ft_strpbrk
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
	#include <stddef.h>

	char *ft_strpbrk(const char *s1, const char *s2);

	int main(void)
	{
		char	*r1;
		char	*r2;

		r1 = ft_strpbrk("hello world", "wor");
		r2 = ft_strpbrk("hello", "xyz");
		printf("%s\n", r1 ? r1 : "(null)");
		printf("%s\n", r2 ? r2 : "(null)");
		return (0);
	}
	EOF
	$(CC) $(CFLAGS) $(SRC) $(BUILD_DIR)/main.c -o $(BIN)
	ACTUAL=$$($(BIN))
	EXPECTED=$$(printf 'o world\n(null)')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: ft_strpbrk output mismatch"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) || exit 1
	fi
	echo "PASS: ft_strpbrk"

clean:
	rm -rf $(BUILD_DIR)
