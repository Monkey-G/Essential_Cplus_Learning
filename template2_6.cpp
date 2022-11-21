#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

inline int max(int n1, int n2){
	return n1 > n2 ? n1 : n2;
};

inline float max(float n1, float n2) {
	return n1 > n2 ? n1 : n2;
};

inline string max(string n1, string n2) {
	return n1 > n2 ? n1 : n2;
};

inline int max(vector<int> vec) {
	return *max_element ( vec.begin(), vec.end() );
};
//max_element实质上返回的是该数组或容器中最大值所对应的地址值

inline float max(vector<float> vec) {
	return *max_element(vec.begin(), vec.end());
};

inline string max(vector<string> vec) {
	return *max_element(vec.begin(), vec.end());
};

inline int max(int *arr, int size) {
	return *max_element(arr, arr + size);
};

inline float max(float* arr, int size) {
	return *max_element(arr, arr + size);
};

inline string max(string* arr, int size) {
	return *max_element(arr, arr + size);
};

int main() {

	int size = 4;

	int iarr[] = { 1, 2, 3, 4 };
	vector<int> ivec (iarr, iarr+ size);

	float farr[] = { 1.1, 2.2, 3.3, 4.4 };
	vector<float> fvec(farr, farr + size);

	string sarr[] = { "R", "U", "ready", "?" };
	vector<string> svec(sarr, sarr + size);

	int imax = max ( max(iarr, size), max(ivec) );
	cout << imax;

}