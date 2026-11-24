int fib(int n)
{
	int a = 0;
	int b = 1;
	int t;

	while (n--) {
		t = a + b;
		a = b;
		b = t;
	}
	return a;
}
