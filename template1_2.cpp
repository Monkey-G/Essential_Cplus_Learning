#include <iostream>
#include <string>
using namespace std;//申明std库，从而可以使用std内的class(std库包括了string)

int main() {
	string user_name,user_answer;
	cout << " Please enter your name: "
	     << '\n';
	cin >> user_name;
	cout << '\n'
		<< "Hello,"
		<< user_name
		<<", would you like to play a game?(Y/N) "
		<< '\n';
	cin >> user_answer;

	int user_right = 0;
	int user_try = 0;
	const int max_try = 5;
	while (user_answer == "Y" && user_right == 0 && user_try < max_try) {
		int user_guest;
		cout << '\n'
			 << "The value 2,3 for two consecutive elements of a numerical sequence. What is the next value? "
			 << '\n';
		cin >> user_guest;
		if (user_guest == (2+3)) {
			user_right++;
			user_try++;
			cout << "You are right,and your pass rate of the question is"
				 << (double)((double)user_right / (double)user_try)
			     << '\n';
		}
		else {
			user_try++;
			cout << "You are wasted,and your pass rate of the question is"
				<< (double)((double)user_right / (double)user_try)
				<< '\n';
			if (user_try != max_try) {
				cout << "Please try again"
					 << '\n';
			}
			else {
				cout << "Haha, you try hard, but the correct answer is 5"
					 << '\n';
			}
		}
	}
	return 0;
}