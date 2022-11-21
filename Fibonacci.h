#include<vector>
#include"num_sequence.h"

class Fibonacci : public num_sequence {
public:
	Fibonacci( int len = 1, int beg_pos = 1 )
		: _length( len ), _beg_pos( beg_pos ) {}//constructor，默认长度和开始位置均为1
	//不设置Fibonacci的destructor

	int                  elem( int pos ) const; //返回pos位置上Fibonacci的数
	const char*          who_am_i() const { return "Fibonacci"; }//数列类型为Fibonacci
	ostream&             print( ostream &os = cout ) const;//打印数列Fibonacci
	int                  length() const { return _length; }//返回数列长度
	int                  beg_pos() const { return _beg_pos; }//返回数列开始位置

protected:
	void                 gen_elems( int pos ) const;//产生元素直至pos位置上
	int                  _length;//长度
	int                  _beg_pos;//数列开始位置

	//!静态成员变量必须在类实例生成之前构造，所以会在编译期构造,
	//! 所以这个_elems是必须要初始化即在class体外初始化static vector<int>   _elems = {};
	//! 或者在函数前边加一个inline表示为内联函数，在第一次编译到这个变量的时候就会初始化，（C++ std17才支持这个特性）
	//! 否则没有初始化的话，就不会分配内存，
	//! 而且静态成员变量属于这个类共享的，在编译的时候就会创建，
	//! 所以链接器肯定找不到，因此会编译错误，
	//! （等以后水平上去了再多看看）
	static vector<int>   _elems;//储存Fibonacci数列的容器
};

vector<int> Fibonacci::_elems = {};

int Fibonacci::
elem( int pos ) const {
	if ( !check_integrity( pos ) )
		return 0;

	if ( pos > _elems.size() )
		Fibonacci::gen_elems( pos );

	return _elems[ pos - 1 ];
}

ostream& Fibonacci::
print( ostream &os ) const {
	int elem_pos = _beg_pos;//打印出来的第一个数的对应的位置
	int end_pos = elem_pos + (_length - 1);//打印出来的最后一个数的对应的位置

	if ( end_pos > _elems.size() )
		Fibonacci::gen_elems( end_pos );

	while ( elem_pos <= end_pos )
		os << _elems[ (elem_pos++) - 1 ] << " ";

	return os;
}

void Fibonacci::
gen_elems( int pos ) const {
	if ( _elems.empty() ) {//初始化
		_elems.push_back( 1 ); _elems.push_back( 1 );}

	if ( _elems.size() <= pos ) {//不可能存在_elems.size() = 1 的情况，因为在定义_elems时，它是空的，则它在开始储存数值之初一定会经过上述的初始化
		int ix = _elems.size();
		int n2 = _elems[ ix - 2 ];
		int n1 = _elems[ ix - 1 ];

		for ( ; ix <= pos; ++ix ) {
			int elem = n2 + n1;
			_elems.push_back( elem );
			n2 = n1; n1 = elem;
		}
	}
}

