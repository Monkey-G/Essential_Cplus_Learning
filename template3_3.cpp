#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

template <typename VecType, typename ElemType>
const vector<VecType> sub_vec(const std::vector<VecType>& vec, const ElemType& val) {
	vector<VecType> local_vec(vec);
	sort(local_vec.begin(), local_vec.end());

	 typename std::vector<VecType>::iterator iter =
		find_if(local_vec.begin(), local_vec.end(), bind2nd(greater<int>(), val));
	 //迭代器也是一个模板类，必须要指明对应类型,函数前仅对Vector的类型和参数类型进行了声明，
	 //未对迭代器类型进行了声明，若想把这个声明也放在函数前，应该先typedef来宏定义其typename，
	 //然后在函数前进行声明；否则就必须像这样在这里加typename来进行声明。

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