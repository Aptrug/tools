NAME		= sort_list
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
	#include "list.h"

	t_list *sort_list(t_list *lst, int (*cmp)(int, int));

	int ascending(int a, int b)
	{
		return (a <= b);
	}

	int descending(int a, int b)
	{
		return (a >= b);
	}

	void print_list(t_list *lst)
	{
		while (lst)
		{
			printf("%d", lst->data);
			lst = lst->next;
			if (lst)
				printf(" ");
		}
		printf("\n");
	}

	int main(void)
	{
		t_list	nodes[6];
		t_list	*sorted;
		t_list	single[1];

		nodes[0].data = 5; nodes[0].next = &nodes[1];
		nodes[1].data = 3; nodes[1].next = &nodes[2];
		nodes[2].data = 8; nodes[2].next = &nodes[3];
		nodes[3].data = 3; nodes[3].next = &nodes[4];
		nodes[4].data = 1; nodes[4].next = &nodes[5];
		nodes[5].data = 9; nodes[5].next = NULL;
		sorted = sort_list(nodes, ascending);
		print_list(sorted);
		nodes[0].data = 5; nodes[0].next = &nodes[1];
		nodes[1].data = 3; nodes[1].next = &nodes[2];
		nodes[2].data = 8; nodes[2].next = &nodes[3];
		nodes[3].data = 3; nodes[3].next = &nodes[4];
		nodes[4].data = 1; nodes[4].next = &nodes[5];
		nodes[5].data = 9; nodes[5].next = NULL;
		sorted = sort_list(nodes, descending);
		print_list(sorted);
		single[0].data = 42;
		single[0].next = NULL;
		sorted = sort_list(single, ascending);
		print_list(sorted);
		return (0);
	}
	EOF
	$(CC) $(CFLAGS) -I. $(SRC) $(BUILD_DIR)/main.c -o $(BIN)
	ACTUAL=$$($(BIN))
	EXPECTED=$$(printf '1 3 3 5 8 9\n9 8 5 3 3 1\n42')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: sort_list output mismatch"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) || exit 1
	fi
	echo "PASS: sort_list"

clean:
	rm -rf $(BUILD_DIR)
