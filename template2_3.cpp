#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool pent_cal (vector<int> &vec, int pos);
void display (vector<int> &vec, const string &title, ostream &os = cout);

int main() {

	vector<int> pent;
	int usr_pos;
	const string title("Pentagonal Numeric Series: ");

	cout << "I would like to show U the Pentagonal numeric series. Please tell me a limition that U wana:" << " ";
	cin >> usr_pos;

	if (pent_cal(pent, usr_pos)) {
		display(pent, title);
	}
}

bool pent_cal(vector<int> &vec, int pos)
{
	if (pos <= 0 || pos > 64) {
		cerr << "Sorry, Invalid position: "
			<< pos << endl;
		return false;
	}
	for (int ix = vec.size() + 1; ix <= pos; ++ix ) {
		vec.push_back( (ix*(3*ix-1))/2 );
	}
}

void display(vector<int> &vec, const string &title, ostream &os)
{
	os << '\n' << title << "\n\t";//"\n\t"不可以写为'\n\t'
	for (int ix = 0; ix < vec.size(); ++ix)
		os << vec[ ix ] << ' ';
	os << endl;
}
