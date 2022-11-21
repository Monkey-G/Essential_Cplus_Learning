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

	ofstream ofile_odd("E:\\手撕代码\\template\\template3_7_odd.txt"),
		     ofile_even("E:\\手撕代码\\template\\template3_7_even.txt");
	if ( !ofile_odd || !ofile_even ) {
		cerr << "Unable to open file -- bailing out!\n";
		return -1;
	}

	vector<int> ivec;//读取的整数
	istream_iterator<int> in(cin), eos;
	//该行的第一个泛型指针绑定至cin以表示从cin获取数据
	//第二个泛型指针指向cin输入流的尾部
	//在输入最后一个数据后，需要回车后Ctrl+z后再回车表示输入结束（Windows指令）
	copy ( in, eos, back_inserter( ivec ) );//第三部分需要是一个指针

	vector<int>::iterator division = stable_partition( ivec.begin(), ivec.end(), odd_elem() );//分离奇偶
	 
	ostream_iterator<int> odd_iter( ofile_odd, " " ),
		                 even_iter( ofile_even, "\n" );

	copy( ivec.begin(), division, odd_iter );
	copy( division, ivec.end(), even_iter );

}
