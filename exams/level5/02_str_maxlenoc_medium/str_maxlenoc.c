#include <unistd.h>

/* Helper function to check if a substring exists in a string */
int contains(char *str, char *sub, int sub_len)
{
	int i;
	int j;

	i = 0;
	while (str[i]) {
		j = 0;
		while (j < sub_len && str[i + j] && str[i + j] == sub[j])
			++j;
		if (j == sub_len)
			return 1;
		i++;
	}
	return 0;
}

int ft_strlen(char *str)
{
	char *start;

	start = str;
	while (*str)
		++str;
	return (str - start);
}

int main(int argc, char **argv)
{
	int max_len;
	int best_start;
	int len1;
	int i;
	int len;
	int k;
	int valid;

	max_len = 0;
	best_start = 0;
	len1 = 0;

	if (argc <= 1) {
		write(1, "\n", 1);
		return (0);
	}

	len1 = ft_strlen(argv[1]);

	i = 0;
	while (i < len1) {
		len = max_len + 1;
		while (i + len <= len1) {
			valid = 1;
			k = 2;
			while (k < argc) {
				if (!contains(argv[k], &argv[1][i], len)) {
					valid = 0;
					break;
				}
				++k;
			}
			if (valid) {
				max_len = len;
				best_start = i;
			} else {
				break;
			}
			++len;
		}
		++i;
	}
	if (max_len > 0)
		write(1, &argv[1][best_start], max_len);
	write(1, "\n", 1);
	return 0;
}
