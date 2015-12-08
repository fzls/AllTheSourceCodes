#include <iostream>
#include "Fibcico.h"

using namespace std;



int main() {
	int n;
	cin >> n;
	Fibcico fib(n);
	fib.solve();
	system("pause");
}