#include <stdio.h>
int main() {
	int a, b;
	for (;;)
	{
		scanf("(%d,%d)", &a, &b);
		fflush(stdin);
		if (a == 0 && b == 0)
			break;
	}

	return 0;
}
