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
	 //������Ҳ��һ��ģ���࣬����Ҫָ����Ӧ����,����ǰ����Vector�����ͺͲ������ͽ�����������
	 //δ�Ե��������ͽ�����������������������Ҳ���ں���ǰ��Ӧ����typedef���궨����typename��
	 //Ȼ���ں���ǰ��������������ͱ����������������typename������������

	local_vec.erase(iter, local_vec.end());
	return local_vec;
};

int main() {

	const int elem_size = 8;

	int iarr[elem_size] = { 12, 8, 43, 0, 6, 21, 3, 7 };
	std::vector<int> ivec(iarr, iarr + elem_size);

	std::vector<int> sub_ivec(sub_vec(ivec, elem_size));
	//ע��vector�ĳ�ʼ����ʽ

	cout << "The members whose value are less than 8:\n";

	for (int ix = 0; ix < sub_ivec.size(); ix++) {
		cout << sub_ivec[ix] << " ";
	}
	cout << endl;

}