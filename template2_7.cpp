#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

template <typename Tpye>
inline Tpye max(Tpye n1, Tpye n2) {
	return n1 > n2 ? n1 : n2;
};

template <typename vTpye>
inline vTpye max(const vector<vTpye> &vec) {
	return *max_element(vec.begin(), vec.end());
};
//max_element实质上返回的是该数组或容器中最大值所对应的地址值

template <typename aTpye>
inline aTpye max(const aTpye* arr, int size) {
	return *max_element(arr, arr + size);
};

int main() {

	int size = 4;

	int iarr[] = { 1, 2, 3, 4 };
	vector<int> ivec(iarr, iarr + size);

	float farr[] = { 1.1, 2.2, 3.3, 4.4 };
	vector<float> fvec(farr, farr + size);

	string sarr[] = { "R", "U", "ready", "?" };
	vector<string> svec(sarr, sarr + size);

	float fmax = ::max( ::max(fvec), ::max(farr, size) );
	//由于系统也有提供max函数，故在命名时要有所注意，
	//对于自定义函数被判定为与系统所定义函数重载时，
	//可以尝试更改自定义函数名称、不使用using namespace std
	//或者将调用改为以上情况“::max( max(fvec), max(farr, size) )”
	//这表示调用本文件中的max函数（::前无指定文件即默认指定本文件）
	//养成指定调用函数时指定文件的习惯！！！！！
	cout << fmax;

}