NAME		= ft_list_foreach
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

	void ft_list_foreach(t_list *begin_list, void (*f)(void *));

	void print_str(void *data)
	{
		printf("%s\n", (char *)data);
	}

	int main(void)
	{
		t_list	c;
		t_list	b;
		t_list	a;

		c.data = "world";
		c.next = NULL;
		b.data = "42";
		b.next = &c;
		a.data = "hello";
		a.next = &b;
		ft_list_foreach(&a, print_str);
		ft_list_foreach(NULL, print_str);
		return (0);
	}
	EOF
	$(CC) $(CFLAGS) -I. $(SRC) $(BUILD_DIR)/main.c -o $(BIN)
	ACTUAL=$$($(BIN))
	EXPECTED=$$(printf 'hello\n42\nworld')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: ft_list_foreach output mismatch"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) ft_list.h || exit 1
	fi
	echo "PASS: ft_list_foreach"

clean:
	rm -rf $(BUILD_DIR)
