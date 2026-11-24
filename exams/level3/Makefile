EXDIRS	= 00_paramsum_easy 01_print_hex_easy 02_lcm_easy \
	  03_pgcd_easy 04_epur_str_easy-medium 05_expand_str_easy-medium \
	  06_tab_mult_easy-medium 07_add_prime_sum_easy-medium 08_ft_atoi_base_medium \
	  09_ft_range_medium 10_ft_rrange_medium 11_ft_list_size_medium \
	  12_hidenp_medium 13_str_capitalizer_medium-hard 14_rstr_capitalizer_medium-hard

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
