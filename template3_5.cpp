#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

class Less_than {
public:
	bool operator()(const string& s1, const string& s2) {
		return (s1.size() < s2.size());
	}
};//定义function object


template< typename elemType >
void display(const vector<elemType>& vec, ostream& os = cout) {
	int len = 5;
	typename vector<elemType>::const_iterator it = vec.begin(),
		end_of_it = vec.end();

	int elem_cnt = 1;
	while (it != end_of_it)
		os << *it++ << (!(elem_cnt++ % len) ? '\n' : ' ');
	os << endl;
}

int main() {

	ifstream ifile("E:\\手撕代码\\template\\template3_4.txt");
	ofstream ofile("E:\\手撕代码\\template\\template3_4_sort.txt");
	if (!ifile || !ofile) {
		cerr << "Unable to open file -- bailing out!\n";
		return -1;
	}

	std::vector<string> svec;
	string word;

	while (ifile >> word)
		svec.push_back(word);//先将ifile的数据传进来

	sort(svec.begin(), svec.end());
	sort(svec.begin(), svec.end(), Less_than());

	display(svec, ofile);

}
