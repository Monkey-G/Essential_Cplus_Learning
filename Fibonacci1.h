#include"num_sequence1.h"

class Fibonacci : public num_sequence {
public:
	Fibonacci(int len = 1, int beg_pos = 1);//constructor声明，默认长度和开始位置均为1
	//不设置Fibonacci的destructor

	const char*          who_am_i() const { return "Fibonacci"; }//数列类型为Fibonacci

protected:
	void                 gen_elems( int pos ) const;//产生元素直至pos位置上
	//!静态成员变量必须在类实例生成之前构造，所以会在编译期构造,
	//! 所以这个_elems是必须要初始化即在class体外初始化static vector<int>   _elems = {};
	//! 或者在函数前边加一个inline表示为内联函数，在第一次编译到这个变量的时候就会初始化，（C++ std17才支持这个特性）
	//! 否则没有初始化的话，就不会分配内存，
	//! 而且静态成员变量属于这个类共享的，在编译的时候就会创建，
	//! 所以链接器肯定找不到，因此会编译错误，
	//! （等以后水平上去了再多看看）
	static vector<int>   _elems;//储存Fibonacci数列的容器
};

//!一定要有对num_sequence constructor的调用操作，否则num_sequence不知道调用哪一具体数列的constructor
inline Fibonacci::
Fibonacci(int len, int beg_pos)
	: num_sequence( len, beg_pos, _elems ){}

vector<int> Fibonacci::_elems = {};

void Fibonacci::
gen_elems( int pos ) const {
	if ( _elems.empty() ) {//初始化
		_elems.push_back( 1 ); _elems.push_back( 1 );
	}

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

