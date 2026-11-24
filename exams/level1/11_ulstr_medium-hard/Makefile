NAME		= ulstr
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
		$(BIN) "L'eSPrit nE peUt plUs pRogResSer s'Il staGne et sI peRsIsTent VAnIte et auto-justification."; \
		$(BIN) "S'enTOuRer dE sECreT eSt uN sIGnE De mAnQuE De coNNaiSSanCe.  "; \
		$(BIN) "3:21 Ba  tOut  moUn ki Ka di KE m'en Ka fe fot"; \
		$(BIN); \
	} | cat -e)
	EXPECTED=$$(printf '%s\n%s\n%s\n%s' \
		"l'EspRIT Ne PEuT PLuS PrOGrESsER S'iL STAgNE ET Si PErSiStENT vaNiTE ET AUTO-JUSTIFICATION.\$$" \
		"s'ENtoUrER De SecREt EsT Un SigNe dE MaNqUe dE COnnAIssANcE.  \$$" \
		"3:21 bA  ToUT  MOuN KI kA DI ke M'EN kA FE FOT\$$" \
		"\$$")
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: ulstr output mismatch"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) || exit 1
	fi
	echo "PASS: ulstr"

clean:
	rm -rf $(BUILD_DIR)
