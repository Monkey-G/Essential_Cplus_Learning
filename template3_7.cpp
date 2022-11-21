#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

class odd_elem {
public:
	bool operator()(int elem) {
		return (elem % 2);
	}
};

int main() {

	ofstream ofile_odd("E:\\��˺����\\template\\template3_7_odd.txt"),
		     ofile_even("E:\\��˺����\\template\\template3_7_even.txt");
	if ( !ofile_odd || !ofile_even ) {
		cerr << "Unable to open file -- bailing out!\n";
		return -1;
	}

	vector<int> ivec;//��ȡ������
	istream_iterator<int> in(cin), eos;
	//���еĵ�һ������ָ�����cin�Ա�ʾ��cin��ȡ����
	//�ڶ�������ָ��ָ��cin��������β��
	//���������һ�����ݺ���Ҫ�س���Ctrl+z���ٻس���ʾ���������Windowsָ�
	copy ( in, eos, back_inserter( ivec ) );//����������Ҫ��һ��ָ��

	vector<int>::iterator division = stable_partition( ivec.begin(), ivec.end(), odd_elem() );//������ż
	 
	ostream_iterator<int> odd_iter( ofile_odd, " " ),
		                 even_iter( ofile_even, "\n" );

	copy( ivec.begin(), division, odd_iter );
	copy( division, ivec.end(), even_iter );

}
