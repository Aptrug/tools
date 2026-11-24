#include <unistd.h>

int main(int argc, char **argv)
{
	char *str;
	char mem[2048] = {0};
	char *ptr = mem;
	int loop;

	if (argc != 2)
		return (0);

	str = argv[1];

	while (*str) {
		if (*str == '>')
			ptr++;
		else if (*str == '<')
			ptr--;
		else if (*str == '+')
			++(*ptr);
		else if (*str == '-')
			--(*ptr);
		else if (*str == '.')
			write(1, ptr, 1);
		else if (*str == '[' && *ptr == 0) {
			loop = 1;
			while (loop) {
				str++;
				if (*str == '[')
					loop++;
				if (*str == ']')
					loop--;
			}
		} else if (*str == ']' && *ptr != 0) {
			loop = 1;
			while (loop) {
				str--;
				if (*str == ']')
					loop++;
				if (*str == '[')
					loop--;
			}
		}
		str++;
	}

	return 0;
}
