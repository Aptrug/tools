NAME		= str_maxlenoc
SRC		= $(NAME).c

CC		:= $(shell command -v clang 2>/dev/null || echo cc)
CFLAGS		= -ansi -pedantic-errors -Wall -Wextra -Werror -pipe

BUILD_DIR	= .build
BIN		= $(BUILD_DIR)/test_$(NAME)

.ONESHELL:

.PHONY: test clean

# if command -v norminette >/dev/null 2>&1; then
# 	norminette -R CheckForbiddenSourceHeader $(SRC) || exit 1
# fi
test:
	set -e
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(SRC) -o $(BIN)
	ACTUAL=$$( { \
		$(BIN) ab bac abacabccabcb; \
		$(BIN) bonjour salut bonjour bonjour; \
		$(BIN) xoxAoxo xoxAox oxAox oxo A ooxAoxx oxooxo Axo; \
		$(BIN) bosdsdfnjodur atehhellosd afkuonjosurafg headfgllosf fghellosag afdfbosnjourafg; \
		$(BIN); \
		$(BIN) hello; \
		$(BIN) abc abc abc; \
	} | cat -e)
	EXPECTED=$$(printf 'a$$\nu$$\n$$\nos$$\n$$\nhello$$\nabc$$')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: str_maxlenoc output mismatch"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	echo "PASS: str_maxlenoc"

clean:
	rm -rf $(BUILD_DIR)
