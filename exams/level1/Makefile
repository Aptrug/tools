EXDIRS	= 00_ft_strlen_easy 01_ft_swap_easy 02_ft_putstr_easy \
	  03_ft_strcpy_easy-medium 04_first_word_easy-medium 05_last_word_easy-medium \
	  06_fizzbuzz_medium 07_rev_print_medium 08_search_and_replace_medium \
	  09_rot_13_medium-hard 10_rotone_medium-hard 11_ulstr_medium-hard \
	  12_repeat_alpha_hard

.ONESHELL:

.PHONY: test clean

test:
	set -e
	for dir in $(EXDIRS); do
		$(MAKE) -C $$dir test
	done

clean:
	set -e
	for dir in $(EXDIRS); do
		$(MAKE) -C $$dir clean
	done
