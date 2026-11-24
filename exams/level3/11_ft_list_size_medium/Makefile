NAME		= ft_list_size
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
	#include "ft_list.h"
	int ft_list_size(t_list *begin_list);

	int main(void)
	{
		t_list	c;
		t_list	b;
		t_list	a;
		int		data;

		data = 42;
		c.next = NULL;
		c.data = &data;
		b.next = &c;
		b.data = &data;
		a.next = &b;
		a.data = &data;
		printf("%d\n", ft_list_size(&a));
		printf("%d\n", ft_list_size(&b));
		printf("%d\n", ft_list_size(NULL));
		return (0);
	}
	EOF
	$(CC) $(CFLAGS) -I. $(SRC) $(BUILD_DIR)/main.c -o $(BIN)
	ACTUAL=$$($(BIN))
	EXPECTED=$$(printf '3\n2\n0')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: ft_list_size output mismatch"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) ft_list.h || exit 1
	fi
	echo "PASS: ft_list_size"

clean:
	rm -rf $(BUILD_DIR)
