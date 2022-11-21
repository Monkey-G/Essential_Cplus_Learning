#include <iostream>
using namespace std;

extern  bool fibon_elem(int, int&);
//int&为引用，即参数不会因为该函数运行完消失

int main() {

	int pos,elem;
	char ch;
	bool more = true;

	while (more) {

		cout << "Please enter a position: ";
		cin  >> pos;

		if (fibon_elem(pos, elem))
			cout << "element # " << pos
			     << " is " << elem << endl;
		else
			cout << "Sorry, could not calculate element # " 
			     << pos << endl;

		cout << "Would u like to try again? (y/n) ";
		cin  >> ch;
		if (ch != 'y' && ch != 'Y')
			more = false;
		else 
			system("cls");
	}

	return 0;

}

bool fibon_elem(int pos, int& elem) {

	if (pos <= 0 || pos > 100) {

		elem = 0; return false;

	}

	elem = 1;
	int n_2 = 1, n_1 = 1;

	for (int ix = 3; ix <= pos; ++ix) {

		elem = n_2 + n_1;
		n_2 = n_1; n_1 = elem;

	}

	return true;

}