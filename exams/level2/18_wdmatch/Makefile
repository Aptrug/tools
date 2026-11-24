NAME		= wdmatch
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
		$(BIN) "faya" "fgvvfdxcacpolhyghbreda"; \
		$(BIN) "faya" "fgvvfdxcacpolhyghbred"; \
		$(BIN) "quarante deux" "qfqfsudf arzgsayns tsregfdgs sjytdekuoixq "; \
		$(BIN) "error" "rrerrrfiiljdfxjyuifrrvcoojh"; \
		$(BIN); \
	} | cat -e)
	EXPECTED=$$(printf 'faya$$\n$$\nquarante deux$$\n$$\n$$')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: wdmatch output mismatch"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) || exit 1
	fi
	echo "PASS: wdmatch"

clean:
	rm -rf $(BUILD_DIR)
