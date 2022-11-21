#include <iostream>
#include <vector>
#include <string>
using namespace std;

inline bool need_cal(vector<int>& vec, int pos);
void pent_cal(vector<int>& vec, int pos);//������ϸ�����ͬ������������extern����inline,��Ϊ���˺�������Ϊ�Ժ����Ķ��壬�����غ��������Է����������֣�����extern����inline���Ա�ʾ��������
void display(vector<int>& vec, const string& title, ostream& os = cout);

int main() {

	vector<int> pent;
	int usr_pos;
	const string title("Pentagonal Numeric Series: ");

	cout << "I would like to show U the Pentagonal numeric series. Please tell me a limition that U wana:" << " ";
	cin >> usr_pos;

	if (need_cal(pent, usr_pos)) {
		display(pent, title);
	}
}

inline bool need_cal(vector<int>& vec, int pos)
{
	if (pos <= 0 || pos > 64) {
		cerr << "Sorry, Invalid position: "
			<< pos << endl;
		return false;
	}
	if (vec.size() < pos) {
		pent_cal(vec,pos);
	}
}

void pent_cal(vector<int>& vec, int pos)
{
	for (int ix = vec.size() + 1; ix <= pos; ++ix) {
		vec.push_back((ix * (3 * ix - 1)) / 2);
	}
}

void display(vector<int>& vec, const string& title, ostream& os)
{
	os << '\n' << title << "\n\t";//"\n\t"������дΪ'\n\t'
	for (int ix = 0; ix < vec.size(); ++ix)
		os << vec[ix] << ' ';
	os << endl;
}
