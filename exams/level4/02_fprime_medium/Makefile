NAME		= fprime
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
		$(BIN) 225225; \
		$(BIN) 8333325; \
		$(BIN) 9539; \
		$(BIN) 804577; \
		$(BIN) 42; \
		$(BIN) 1; \
		$(BIN); \
		$(BIN) 42 21; \
	} | cat -e)
	EXPECTED=$$(printf '3*3*5*5*7*11*13$$\n3*3*5*5*7*11*13*37$$\n9539$$\n804577$$\n2*3*7$$\n1$$\n$$\n$$')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: fprime output mismatch"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) || exit 1
	fi
	echo "PASS: fprime"

clean:
	rm -rf $(BUILD_DIR)
