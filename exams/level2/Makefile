EXDIRS	= 00_alpha_mirror 01_camel_to_snake 02_snake_to_camel 03_do_op \
	  04_ft_atoi 05_ft_strcmp 06_ft_strcspn 07_ft_strdup 08_ft_strpbrk \
	  09_ft_strrev 10_ft_strspn 11_is_power_of_2 12_max 13_print_bits \
	  14_reverse_bits 15_swap_bits 16_inter 17_union 18_wdmatch \
	  19_count_alpha

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
