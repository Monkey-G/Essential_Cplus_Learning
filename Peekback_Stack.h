#include "Stack1.h"

class Peekback_Stack : public Stack {//下压栈，后进先出
public:
	Peekback_Stack(int capacity = 0) {
		if (capacity) _stack.reserve(capacity);
	}

	virtual bool push(const elemType& elem);//在数列末端添加数
	virtual bool pop(elemType& elem);//在数列末端去除数
	virtual bool peek(int, elemType&); //查看数列任意位置数

	virtual bool empty() const { return !_stack.size(); }//检查数列是否为空
	virtual bool full() const { return _stack.size() >= _stack.max_size(); }//检查数列是否为空
	virtual int size() const { return _stack.size(); }//数列的大小

	virtual void print(ostream& os = cout) const;//打印数列

private:
	vector<elemType> _stack;
};

bool Peekback_Stack::
push(const elemType& elem) {
	if (full())
		return false;
	_stack.push_back(elem);
	return true;
}

bool Peekback_Stack::
pop(elemType& elem) {
	if (empty())
		return false;
	elem = _stack[size() - 1];
	_stack.pop_back();
	return true;
}

bool Peekback_Stack::
peek(int index, elemType& elem) {//索引从0开始
	if ( empty() )
		return false;

	if ( index < 0 || index >= size() )
		return false;

	elem = _stack[ index ];
	return true;
}

ostream& Peekback_Stack::
print(ostream& os) const {
	vector<elemType>::const_reverse_iterator//后进先出，所以要用反向迭代器适配器
		rit = _stack.rbegin(),
		rend = _stack.rend();

	os << "\n\t";
	while (rit != rend)
		os << *rit++ << "\n\t";

	os << endl;
}
