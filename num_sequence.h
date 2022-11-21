#include<iostream>

using namespace std;

class num_sequence {
public:
	//只要基类虚函数有virtual修饰，那么派生类的virtual可以省略。
	//如果你的析构函数只是虚函数，那么派生类中你不写函数体也可以通过编译，只不过用的是上一个基类的版本罢了。而纯虚析构函数
	//派生的类不写析构函数，那么就会用编译器生成的版本。
	virtual ~num_sequence() {};//destructor

	//设置为纯虚函数可以把对虚函数的确切定义交给派生类，而基类仅提供一个接口以供使用
	virtual int          elem( int pos ) const = 0; //返回pos位置上的数
	virtual const char*  who_am_i() const = 0;//判别数列类型
	virtual ostream&     print( ostream &os = cout ) const = 0;//打印数列
	virtual int          length() const = 0;//返回数列长度
	virtual int          beg_pos() const = 0;//返回数列开始位置
	static int           max_elems() { return _max_elems; }//返回目前支持的最大位置值
	//!一个重要知识点static member function是无法被声明为虚函数的

protected:
	virtual void         gen_elems( int pos ) const = 0;//产生元素直至pos位置上
	bool                 check_integrity( int pos ) const; //判别pos是否为有效位置
	const static int     _max_elems = 1024;
};

bool num_sequence::
check_integrity( int pos ) const {
	if ( pos <= 0 || pos > _max_elems ) {
		cerr << "!! Invalid position: " << pos << ". Cannot honor request!\n";
		return false;
	}
	return true;
}

ostream& operator<< ( ostream& os, const num_sequence &ns ) { return ns.print(); }
