#include <iostream>
#include <vector>
#include <functional>
using namespace std;

template <typename InputIterator, typename OutputIterator, 
	typename ElemType, typename Comp>
inline OutputIterator filter(InputIterator first, InputIterator last, 
	OutputIterator at, const ElemType &val, Comp pred) {
	while ((first = find_if(first, last, bind2nd(pred, val))) != last) {
		cout << "Found value : " << *first << endl;
		*at++ = *first++;
	}
	return at;
};
//at 用于声明储存过滤器执行后得到的所需数的新容器的初始储存地址

int main() {

	const int elem_size = 8;

	int iarr[elem_size] = { 12, 8, 43, 0, 6, 21, 3, 7 };
	vector<int> ivec(iarr, iarr + elem_size);

	int iarr2[ elem_size ];
	vector<int> ivec2( elem_size );

	cout << "filtering integer array for values less than 8\n";
	filter(iarr, iarr+ elem_size ,iarr2, elem_size, less<int>());

	cout << "filtering integer array for values less than 8\n";
	filter(ivec.begin(), ivec.end(), ivec2.begin(), elem_size, greater<int>());

}