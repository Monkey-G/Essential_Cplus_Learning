#include <iostream>
#include <vector>
using namespace std;//申明std库，从而可以使用std内的class(std库包括了string)

int main() {

	vector <int> user_ivec;
	int user_ival;
	int in_sum = 0;
	double in_ave = 0;

	while (cin >> user_ival) {
		system("cls");
		user_ivec.push_back(user_ival);
		in_sum += user_ivec[user_ivec.size()-1];
		in_ave = double(in_sum) / double (user_ivec.size());
		cout << "The sum of " << user_ivec.size()
			 << "elements is: " << in_sum << '\n'
			 << "And the average is: " << in_ave <<endl;
	}
	return 0;
}