#include <iostream>
#include <vector>
using namespace std;

void display (vector<int> & vec) {

	for (int ix = 0; ix < vec.size(); ++ix)
		cout << vec[ix] << ' ';
	cout << endl;

}

void swap(int & val1, int & val2) {

	int temp = val1;
	val1 = val2;
	val2 = temp;

}

void bubble_sort(vector<int>& vec) {

	for (int ix = 0; ix < vec.size(); ++ix)
		for (int jx = ix + 1; jx < vec.size(); ++jx)
			if (vec[ix] > vec[jx])
				swap(vec[ix], vec[jx]);

}

int main() {

	cout << "Please cin ur words: ";

	int ia[8] ;
	for (int ix = 0; ix < 8; ++ix)
		cin >> ia[ix];

	vector<int> vec(ia, ia + 8);

	cout << "vector before sort: ";
	display(vec);

	bubble_sort(vec);

	cout << "vector after sort: ";
	display(vec);

}