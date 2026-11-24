NAME		= search_and_replace
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
		$(BIN) "Papache est un sabre" "a" "o"; \
		$(BIN) "zaz" "art" "zul"; \
		$(BIN) "zaz" "r" "u"; \
		$(BIN) "jacob" "a" "b" "c" "e"; \
		$(BIN) "ZoZ eT Dovid oiME le METol." "o" "a"; \
		$(BIN) "wNcOre Un ExEmPle Pas Facilw a Ecrirw " "w" "e"; \
	} | cat -e)
	EXPECTED=$$(printf 'Popoche est un sobre$$\n$$\nzaz$$\n$$\nZaZ eT David aiME le METal.$$\neNcOre Un ExEmPle Pas Facile a Ecrire $$')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: search_and_replace output mismatch"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) || exit 1
	fi
	echo "PASS: search_and_replace"

clean:
	rm -rf $(BUILD_DIR)
