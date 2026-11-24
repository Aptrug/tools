NAME		= ft_split
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
	char **ft_split(char *str);

	void print_split(char *str)
	{
		char	**words;
		int		i;

		words = ft_split(str);
		i = 0;
		while (words[i])
		{
			printf("[%s]", words[i]);
			i++;
		}
		printf("\n");
	}

	int main(void)
	{
		print_split("Hello World  42");
		print_split("   leading and trailing   ");
		print_split("   ");
		print_split("");
		print_split("one\ttwo\nthree");
		print_split("single");
		return (0);
	}
	EOF
	$(CC) $(CFLAGS) $(SRC) $(BUILD_DIR)/main.c -o $(BIN)
	ACTUAL=$$($(BIN))
	EXPECTED=$$(printf '[Hello][World][42]\n[leading][and][trailing]\n\n\n[one][two][three]\n[single]')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: ft_split output mismatch"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) || exit 1
	fi
	echo "PASS: ft_split"

clean:
	rm -rf $(BUILD_DIR)
