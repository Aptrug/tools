NAME		= max
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

	int max(int *tab, unsigned int len);

	int main(void)
	{
		int	t1[] = {3, 7, 2, 9, 4};
		int	t2[] = {-5, -1, -100};
		int	t3[] = {42};

		printf("%d\n", max(t1, 5));
		printf("%d\n", max(t2, 3));
		printf("%d\n", max(t3, 1));
		printf("%d\n", max(t1, 0));
		return (0);
	}
	EOF
	$(CC) $(CFLAGS) $(SRC) $(BUILD_DIR)/main.c -o $(BIN)
	ACTUAL=$$($(BIN))
	EXPECTED=$$(printf '9\n-1\n42\n0')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: max output mismatch"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) || exit 1
	fi
	echo "PASS: max"

clean:
	rm -rf $(BUILD_DIR)
