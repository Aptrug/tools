NAME		= ft_list_remove_if
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
	#include <stdlib.h>
	#include "ft_list.h"

	void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(void *, void *));

	int cmp_int(void *a, void *b)
	{
		return (*(int *)a != *(int *)b);
	}

	t_list *new_node(int value)
	{
		t_list	*node;
		int		*data;

		node = malloc(sizeof(t_list));
		data = malloc(sizeof(int));
		*data = value;
		node->data = data;
		node->next = NULL;
		return (node);
	}

	void print_list(t_list *lst)
	{
		while (lst)
		{
			printf("%d", *(int *)lst->data);
			lst = lst->next;
			if (lst)
				printf(" ");
		}
		printf("\n");
	}

	int main(void)
	{
		t_list	*lst;
		t_list	*empty;
		int		target;
		int		absent;

		lst = new_node(1);
		lst->next = new_node(2);
		lst->next->next = new_node(3);
		lst->next->next->next = new_node(2);
		lst->next->next->next->next = new_node(4);
		target = 2;
		ft_list_remove_if(&lst, &target, cmp_int);
		print_list(lst);
		absent = 42;
		ft_list_remove_if(&lst, &absent, cmp_int);
		print_list(lst);
		target = 1;
		ft_list_remove_if(&lst, &target, cmp_int);
		target = 3;
		ft_list_remove_if(&lst, &target, cmp_int);
		target = 4;
		ft_list_remove_if(&lst, &target, cmp_int);
		print_list(lst);
		empty = NULL;
		ft_list_remove_if(&empty, &target, cmp_int);
		print_list(empty);
		return (0);
	}
	EOF
	$(CC) $(CFLAGS) -I. $(SRC) $(BUILD_DIR)/main.c -o $(BIN)
	ACTUAL=$$($(BIN))
	EXPECTED=$$(printf '1 3 4\n1 3 4\n\n')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: ft_list_remove_if output mismatch"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) ft_list.h || exit 1
	fi
	echo "PASS: ft_list_remove_if"

clean:
	rm -rf $(BUILD_DIR)
