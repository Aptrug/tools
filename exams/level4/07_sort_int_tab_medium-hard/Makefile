NAME		= sort_int_tab
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
	void sort_int_tab(int *tab, unsigned int size);

	void print_tab(int *tab, unsigned int size)
	{
		unsigned int	i;

		i = 0;
		while (i < size)
		{
			printf("%d", tab[i]);
			if (i + 1 < size)
				printf(" ");
			i = i + 1;
		}
		printf("\n");
	}

	int main(void)
	{
		int	a[6];
		int	b[5];
		int	c[4];
		int	d[1];
		int	e[7];

		a[0] = 5; a[1] = 3; a[2] = 8; a[3] = 1; a[4] = 9; a[5] = 2;
		sort_int_tab(a, 6);
		print_tab(a, 6);
		b[0] = 1; b[1] = 2; b[2] = 3; b[3] = 4; b[4] = 5;
		sort_int_tab(b, 5);
		print_tab(b, 5);
		c[0] = 4; c[1] = 3; c[2] = 2; c[3] = 1;
		sort_int_tab(c, 4);
		print_tab(c, 4);
		d[0] = 42;
		sort_int_tab(d, 1);
		print_tab(d, 1);
		sort_int_tab(d, 0);
		print_tab(d, 1);
		e[0] = 3; e[1] = -1; e[2] = 3; e[3] = 0; e[4] = -1; e[5] = 3; e[6] = 0;
		sort_int_tab(e, 7);
		print_tab(e, 7);
		return (0);
	}
	EOF
	$(CC) $(CFLAGS) $(SRC) $(BUILD_DIR)/main.c -o $(BIN)
	ACTUAL=$$($(BIN))
	EXPECTED=$$(printf '1 2 3 5 8 9\n1 2 3 4 5\n1 2 3 4\n42\n42\n-1 -1 0 0 3 3 3')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: sort_int_tab output mismatch"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) || exit 1
	fi
	echo "PASS: sort_int_tab"

clean:
	rm -rf $(BUILD_DIR)
