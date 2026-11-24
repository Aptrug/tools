#include <unistd.h>

/* Helper function to print a positive integer using only write */
void ft_putnbr(int n)
{
	char c;

	if (n >= 10)
		ft_putnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

void print_help(void)
{
	write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36);
}

void print_invalid(void)
{
	write(1, "Invalid Option\n", 15);
}

int main(int argc, char **argv)
{
	int flags;
	char *str;

	if (argc <= 1) {
		print_help();
		return (0);
	}
	flags = 0;
	++argv;

	while (*argv) {
		str = *argv;
		if (*str != '-') {
			print_invalid();
			return (0);
		}
		++str;
		if (!*str) {
			print_invalid();
			return (0);
		}
		while (*str) {
			if (*str == 'h') {
				print_help();
				return (0);
			} else if (*str >= 'a' && *str <= 'z') {
				flags = flags | (1 << (*str - 'a'));
			} else {
				print_invalid();
				return (0);
			}
			++str;
		}
		++argv;
	}
	ft_putnbr(flags);
	write(1, "\n", 1);

	return (0);
}
