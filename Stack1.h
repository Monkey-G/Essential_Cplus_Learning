#include<string>
#include<vector>
#include<iostream>

using namespace std;

typedef string elemType;//����template����

class Stack {//member function����class�ڶ���������ڳ����ڶ���
public:
	virtual ~Stack(){}
	virtual bool push( const elemType& ) = 0;//������ĩ�������
	virtual bool pop( elemType& ) = 0;//������ĩ��ȥ����
	virtual bool peek( int, elemType& ) = 0;//�鿴��������λ����

	virtual bool empty() const = 0;//��������Ƿ�Ϊ��
	virtual bool full() const = 0;//��������Ƿ�Ϊ��
	virtual int size() const = 0;//���еĴ�С

	virtual void print( ostream& = cout ) const = 0;//��ӡ����
};

ostream& operator<< ( ostream &os, const Stack &rhs ) {
	rhs.print();
	return os;
}