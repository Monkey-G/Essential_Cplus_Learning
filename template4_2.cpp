#include "Stack.h"

inline bool Stack::push(const string& elem) {
	if (full())
		return false;
	_stack.push_back(elem);
	return true;
}

inline bool Stack::pop(string& elem) {
	if (empty())
		return false;
	elem = _stack.back();
	_stack.pop_back();
	return true;
}

inline bool Stack::peek(string& elem) {
	if (empty())
		return false;
	elem = _stack.back();
	return true;
}

inline bool Stack::find(const string& elem) {
	if (empty())
		return false;
	vector<string>::iterator iter = ::find(_stack.begin(), _stack.end(), elem);
	return (iter != _stack.end());
}

inline int Stack::count(const string& elem) {
	if (empty())
		return 0;
	return ::count(_stack.begin(), _stack.end(), elem);
}

int main() {

	Stack stack;
	string str;

	while (cin >> str && !stack.full())
		stack.push(str);

	cin.clear();//清除end-of-file的设定!!!!!

	system("cls");

	if (stack.empty()) {
		cout << '\n' << "Oops: no strings were read -- bailing out.\n";
		return -1;
	}
	else {
		string usr_answer;
		cout << "Check the existence of entered value?\n ";
		cin >> usr_answer;
		while (usr_answer == "Y" || usr_answer == "y") {
			system("cls");

			cout << "PLease enter the value.\n ";
			string usr_value;
			cin >> usr_value;
			cout << usr_value << (stack.find(usr_value) ? " is " : " isn't ") << "in the stack.\n";

			cout << "Would U like to check more?(Y/y or N/n) \n";
			cin >> usr_answer;
		}//用户查询
		system("cls");

		cout << "Would U like to count the entered value?\n ";
		cin >> usr_answer;
		while (usr_answer == "Y" || usr_answer == "y") {
			system("cls");

			cout << "PLease enter the value.\n ";
			string usr_value;
			cin >> usr_value;
			cout << usr_value << " occurs " << stack.count(usr_value) << " times.\n";

			cout << "Would U like to check more?(Y/y or N/n) \n";
			cin >> usr_answer;
		}//用户查询
		system("cls");

		cout << "Read in " << stack.size() << "strings: \n";
		stack.display_total_string();
		cout << "\n" << "Read in " << stack.size() << " strings in reverse order: \n";
		while (stack.size())
			if (stack.pop(str))
				cout << str << ' ';
	}

	cout << "\n" << "There are now " << stack.size() << "elements in the stack!\n";

}