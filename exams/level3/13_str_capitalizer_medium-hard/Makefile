NAME		= str_capitalizer
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
		echo "FAIL: str_capitalizer output mismatch (no args)"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	ACTUAL=$$($(BIN) "a FiRSt LiTTlE TESt" | cat -e)
	EXPECTED=$$(printf 'A First Little Test$$')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: str_capitalizer output mismatch (single arg)"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	ACTUAL=$$($(BIN) "__SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "     Okay, this is the last 1239809147801 but not    the least    t" | cat -e)
	EXPECTED=$$(printf '__second Test A Little Bit   Moar Complex$$\n   But... This Is Not That Complex$$\n     Okay, This Is The Last 1239809147801 But Not    The Least    T$$')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: str_capitalizer output mismatch (multi arg)"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) || exit 1
	fi
	echo "PASS: str_capitalizer"

clean:
	rm -rf $(BUILD_DIR)
