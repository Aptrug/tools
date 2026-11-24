NAME		= rstr_capitalizer
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
	ACTUAL=$$($(BIN) | cat -e)
	EXPECTED=$$(printf '$$')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: rstr_capitalizer output mismatch (no args)"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	ACTUAL=$$($(BIN) "a FiRSt LiTTlE TESt" | cat -e)
	EXPECTED=$$(printf 'A firsT littlE tesT$$')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: rstr_capitalizer output mismatch (single arg)"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	ACTUAL=$$($(BIN) "SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "     Okay, this is the last 1239809147801 but not    the least    t" | cat -e)
	EXPECTED=$$(printf 'seconD tesT A littlE biT   moaR compleX$$\n   buT... thiS iS noT thaT compleX$$\n     okaY, thiS iS thE lasT 1239809147801 buT noT    thE leasT    T$$')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: rstr_capitalizer output mismatch (multi arg)"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) || exit 1
	fi
	echo "PASS: rstr_capitalizer"

clean:
	rm -rf $(BUILD_DIR)
