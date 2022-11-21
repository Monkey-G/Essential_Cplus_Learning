#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

const vector<int> sub_vec(const std::vector<int>& vec, const int & val) {
	vector<int> local_vec(vec);
	sort(local_vec.begin(), local_vec.end());

	std::vector<int>::iterator iter =
		find_if(local_vec.begin(), local_vec.end(), bind2nd(greater<int>(), val));

	local_vec.erase(iter, local_vec.end());
	return local_vec;
};

int main() {

	const int elem_size = 8;

	int iarr[elem_size] = { 12, 8, 43, 0, 6, 21, 3, 7 };
	std::vector<int> ivec(iarr, iarr + elem_size);

	std::vector<int> sub_ivec(sub_vec(ivec, elem_size));
	//注意vector的初始化方式

	cout << "The members whose value are less than 8:\n";

	for (int ix = 0; ix < sub_ivec.size(); ix++) {
		cout << sub_ivec[ix] << " ";
	}

	cout << endl;

}