#include <iostream>
#include <vector>
#include <string>
using namespace std;

inline bool need_cal(int cap, int pos);
void display(int cap, int pos, int& usr_gotnum, const string& title);

const vector<int>* pent_cal(int cap, int pos)
{
	static vector<int> elems;
	if (need_cal(cap, pos) && (cap > elems.size())) {
		for (int ix = elems.size() + 1; ix <= cap; ++ix) {
			elems.push_back((ix * (3 * ix - 1)) / 2);
		}
	}
	return &elems;
}

int main() {

	int usr_cap;
	int usr_pos;
	int usr_gotnum;
	const string title("The number U wanna: ");

	cout << "I would like to get Ur favourable capacity of the Pentagonal numeric series and the position of the Pentagonal numeric series that U wanna. Please tell me:" << " ";
	cin >> usr_cap;
	cin >> usr_pos;

	if (need_cal(usr_cap, usr_pos)) {
		display(usr_cap,usr_pos, usr_gotnum,title);
	}
}

inline bool need_cal(int cap, int pos)
{
	if (cap <= 0 || cap > 64) {
		cerr << "Sorry, Invalid capacity: "
			<< cap << endl;
		return false;
	}
	if (pos <= 0 || pos > 64 || pos > cap) {
		cerr << "Sorry, Invalid position: "
			<< pos << endl;
		return false;
	}
}

void display(int cap, int pos,int& usr_gotnum, const string& title)
{
	cout << '\n' << title << "\n\t";//"\n\t"不可以写为'\n\t'
	const vector<int>* pent = pent_cal(cap, pos);
	usr_gotnum = (*pent) [pos - 1];
	cout << usr_gotnum << ' ';
	cout << endl;
}