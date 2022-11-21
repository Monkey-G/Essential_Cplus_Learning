#include <iostream>
#include <string>
using namespace std;//申明std库，从而可以使用std内的class(std库包括了string)

int main() {

	string user_name[2], user_answer;

	cout << " Please enter your name: "
		 << '\n';

	cin >> user_name[0]
		>> user_name[1];

	cout << '\n'
		<< "Hello,"
		<< user_name[0]
		<< " "
		<< user_name[1]
		<< ", could you enter something that you wanna talk to me?(Y/N) "
		<< '\n';

	cin >> user_answer;

	if (user_answer == "Y" || user_answer == "y") {
		string user_in;

		cout << '\n'
			<< "Well, what do you wanna talk with me? "
			<< '\n';

		int in_time = 1;
		const int in_max = 3;

		cin >> user_in;

		while (user_in.size() <= 2 && in_time < in_max) {
			cout << "Hummm, I think that you would like to talk more with me, how about talking again?";

			cin >> user_in;

			in_time++;
		}

		if (in_time == in_max) {
			cout << "Well, I would like to have a chance to hear your talking in the future again";
		}

		else {
			cout << "Well, your talking is wonderful!!";
		}
	}

	else 
		if (user_answer == "N" || user_answer == "n") {
		cout << "Hummm, Okay.See you later";
		}
		else {
		cout << "?";
		}
	return 0;
}