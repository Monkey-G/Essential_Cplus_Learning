//#include"Fibonacci.h"
#include"Fibonacci1.h"

int main() {
	Fibonacci fib1;
	Fibonacci fib2(16, 1);
	Fibonacci fib3(8, 12);

	cout << "fib1: beginnig at element 1 for 1 element: " << fib1 << endl;
	cout << "fib2: beginnig at element 1 for 16 element: " << fib2 << endl;
	cout << "fib3: beginnig at element 12 for 8 element: " << fib3 << endl;
}