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
//max_elementʵ���Ϸ��ص��Ǹ���������������ֵ����Ӧ�ĵ�ֵַ

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
	//����ϵͳҲ���ṩmax��������������ʱҪ����ע�⣬
	//�����Զ��庯�����ж�Ϊ��ϵͳ�����庯������ʱ��
	//���Գ��Ը����Զ��庯�����ơ���ʹ��using namespace std
	//���߽����ø�Ϊ���������::max( max(fvec), max(farr, size) )��
	//���ʾ���ñ��ļ��е�max������::ǰ��ָ���ļ���Ĭ��ָ�����ļ���
	//����ָ�����ú���ʱָ���ļ���ϰ�ߣ���������
	cout << fmax;

}