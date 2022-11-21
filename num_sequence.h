#include<iostream>

using namespace std;

class num_sequence {
public:
	//ֻҪ�����麯����virtual���Σ���ô�������virtual����ʡ�ԡ�
	//��������������ֻ���麯������ô���������㲻д������Ҳ����ͨ�����룬ֻ�����õ�����һ������İ汾���ˡ���������������
	//�������಻д������������ô�ͻ��ñ��������ɵİ汾��
	virtual ~num_sequence() {};//destructor

	//����Ϊ���麯�����԰Ѷ��麯����ȷ�ж��彻�������࣬��������ṩһ���ӿ��Թ�ʹ��
	virtual int          elem( int pos ) const = 0; //����posλ���ϵ���
	virtual const char*  who_am_i() const = 0;//�б���������
	virtual ostream&     print( ostream &os = cout ) const = 0;//��ӡ����
	virtual int          length() const = 0;//�������г���
	virtual int          beg_pos() const = 0;//�������п�ʼλ��
	static int           max_elems() { return _max_elems; }//����Ŀǰ֧�ֵ����λ��ֵ
	//!һ����Ҫ֪ʶ��static member function���޷�������Ϊ�麯����

protected:
	virtual void         gen_elems( int pos ) const = 0;//����Ԫ��ֱ��posλ����
	bool                 check_integrity( int pos ) const; //�б�pos�Ƿ�Ϊ��Чλ��
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
