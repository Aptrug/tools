EXDIRS	= 00_ft_itoa_easy-medium 01_ft_list_foreach_easy-medium \
	  02_fprime_medium 03_ft_list_remove_if_medium 04_rostring_medium \
	  05_rev_wstr_medium 06_ft_split_medium-hard 07_sort_int_tab_medium-hard \
	  08_sort_list_medium-hard 09_flood_fill_hard

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
