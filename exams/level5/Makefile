EXDIRS	= 00_ft_itoa_base_easy-medium 01_brackets_medium \
	  02_str_maxlenoc_medium 03_print_memory_medium \
	  04_options_medium-hard 05_checkmate_medium-hard \
	  06_rpn_calc_hard 07_brainfuck_hard


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
