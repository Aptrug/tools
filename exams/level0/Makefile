EXDIRS	= 00_only_a_easy 01_only_z_easy 02_hello_easy \
	  03_ft_countdown_easy 04_ft_print_numbers_easy \
	  05_aff_first_param_easy-medium 06_aff_last_param_easy-medium \
	  07_aff_a_easy-medium 08_aff_z_easy-medium \
	  09_maff_alpha_medium 10_maff_revalpha_medium-hard

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
