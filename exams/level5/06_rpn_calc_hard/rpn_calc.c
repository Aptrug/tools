#include <stdio.h>
#include <stdlib.h>

unsigned char is_operator(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

unsigned char is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int main(int argc, char **argv)
{
	int stack[2048];
	int *ptr;
	int a;
	int b;
	char *str;

	if (argc != 2) {
		printf("Error\n");
		return 0;
	}

	str = argv[1];
	ptr = stack;
	while (*str) {
		if (*str == ' ') {
			++str;
			continue;
		}

		/* Check for valid single-character operators */
		if (is_operator(*str) && (str[1] == ' ' || str[1] == '\0')) {

			/* Check stack depth using pointer distance */
			if (ptr - stack < 2) {
				printf("Error\n");
				return 0;
			}

			b = *(--ptr);
			a = *(--ptr);

			if (*str == '+')
				*ptr++ = a + b;
			else if (*str == '-')
				*ptr++ = a - b;
			else if (*str == '*')
				*ptr++ = a * b;
			else if (*str == '/') {
				if (b == 0) {
					printf("Error\n");
					return 0;
				}
				*ptr++ = a / b;
			} else if (*str == '%') {
				if (b == 0) {
					printf("Error\n");
					return 0;
				}
				*ptr++ = a % b;
			}
			++str;
		}
		/* Check for valid numbers (including negative integers) */
		else if (is_digit(*str) || (*str == '-' && is_digit(str[1]))) {
			*ptr++ = atoi(str);

			if (*str == '-')
				++str;
			while (is_digit(*str))
				++str;

			/* Enforce the strict space separation rule */
			if (*str != ' ' && *str != '\0') {
				printf("Error\n");
				return 0;
			}
		}
		/* Invalid token encountered */
		else {
			printf("Error\n");
			return 0;
		}
	}

	/* If exactly one item remains, pop and print it */
	if (ptr == stack + 1)
		printf("%d\n", *--ptr);
	else
		printf("Error\n");

	return 0;
}
