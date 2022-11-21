#include<string>
#include<vector>
#include<iostream>

using namespace std;

typedef string elemType;//方便template操作

class Stack {//member function不在class内定义则必须在程序内定义
public:
	virtual ~Stack(){}
	virtual bool push( const elemType& ) = 0;//在数列末端添加数
	virtual bool pop( elemType& ) = 0;//在数列末端去除数
	virtual bool peek( int, elemType& ) = 0;//查看数列任意位置数

	virtual bool empty() const = 0;//检查数列是否为空
	virtual bool full() const = 0;//检查数列是否为空
	virtual int size() const = 0;//数列的大小

	virtual void print( ostream& = cout ) const = 0;//打印数列
};

ostream& operator<< ( ostream &os, const Stack &rhs ) {
	rhs.print();
	return os;
}