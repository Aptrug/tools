NAME		= inter
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
	$(CC) $(CFLAGS) $(SRC) -o $(BIN)
	ACTUAL=$$( { \
		$(BIN) "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj"; \
		$(BIN) "ddf6vewg64f" "gtwthgdwthdwfteewhrtag6h4ffdhsd"; \
		$(BIN) "rien" "cette phrase ne cache rien"; \
		$(BIN); \
	} | cat -e)
	EXPECTED=$$(printf 'padinto$$\ndf6ewg4$$\nrien$$\n$$')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: inter output mismatch"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) || exit 1
	fi
	echo "PASS: inter"

clean:
	rm -rf $(BUILD_DIR)
