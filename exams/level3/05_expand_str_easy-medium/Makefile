NAME		= expand_str
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
		$(BIN) "See? It's easy to print the same thing"; \
		$(BIN) " this        time it      will     be    more complex  "; \
		$(BIN) "No S*** Sherlock..." "nAw S*** ShErLaWQ..."; \
		$(BIN) ""; \
	} | cat -e)
	EXPECTED=$$(printf "See?   It's   easy   to   print   the   same   thing\$$\nthis   time   it   will   be   more   complex\$$\n\$$\n\$$")
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: expand_str output mismatch"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) || exit 1
	fi
	echo "PASS: expand_str"

clean:
	rm -rf $(BUILD_DIR)
