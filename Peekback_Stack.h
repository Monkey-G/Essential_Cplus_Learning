#include "Stack1.h"

class Peekback_Stack : public Stack {//��ѹջ������ȳ�
public:
	Peekback_Stack(int capacity = 0) {
		if (capacity) _stack.reserve(capacity);
	}

	virtual bool push(const elemType& elem);//������ĩ�������
	virtual bool pop(elemType& elem);//������ĩ��ȥ����
	virtual bool peek(int, elemType&); //�鿴��������λ����

	virtual bool empty() const { return !_stack.size(); }//��������Ƿ�Ϊ��
	virtual bool full() const { return _stack.size() >= _stack.max_size(); }//��������Ƿ�Ϊ��
	virtual int size() const { return _stack.size(); }//���еĴ�С

	virtual void print(ostream& os = cout) const;//��ӡ����

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
peek(int index, elemType& elem) {//������0��ʼ
	if ( empty() )
		return false;

	if ( index < 0 || index >= size() )
		return false;

	elem = _stack[ index ];
	return true;
}

ostream& Peekback_Stack::
print(ostream& os) const {
	vector<elemType>::const_reverse_iterator//����ȳ�������Ҫ�÷��������������
		rit = _stack.rbegin(),
		rend = _stack.rend();

	os << "\n\t";
	while (rit != rend)
		os << *rit++ << "\n\t";

	os << endl;
}
