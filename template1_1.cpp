#include <iostream>
//#include <string>
#include <vector>
using namespace std;//����std�⣬�Ӷ�����ʹ��std�ڵ�class(std�������string)

int main() {
	//string user_name[2];
	vector <string> user_name(2);

	cout << " Please enter your first name and last name: ";

	cin >> user_name[0]
		>> user_name[1];

	cout << '\n'
		<< "Hello,"
		<< user_name[0]
		<< " "
		<< user_name[1]
		<< "... and goodbye!\n ";

	return 0;
}