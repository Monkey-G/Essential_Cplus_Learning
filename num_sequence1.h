#include<iostream>
#include<vector>

using namespace std;

class num_sequence {
public:
	//ֻҪ�����麯����virtual���Σ���ô�������virtual����ʡ�ԡ�
	//��������������ֻ���麯������ô���������㲻д������Ҳ����ͨ�����룬ֻ�����õ�����һ������İ汾���ˡ���������������
	//�������಻д������������ô�ͻ��ñ��������ɵİ汾��
	virtual ~num_sequence() {};//destructor

	//����Ϊ���麯�����԰Ѷ��麯����ȷ�ж��彻�������࣬��������ṩһ���ӿ��Թ�ʹ��
	virtual const char*  who_am_i() const = 0;//�б���������

	int                  elem( int pos ) const; //����posλ���ϵ���
	ostream&             print( ostream &os = cout ) const;//��ӡ����
	int                  length() const { return _length; }//�������г���
	int                  beg_pos() const { return _beg_pos; }//�������п�ʼλ��
	static int           max_elems() { return _max_elems; }//����Ŀǰ֧�ֵ����λ��ֵ
	//!һ����Ҫ֪ʶ��static member function���޷�������Ϊ�麯����

protected:
	num_sequence( int len, int beg_pos, vector<int> &relems )
		: _length( len ), _beg_pos( beg_pos ), _relems( relems ) {}//constructor
	virtual void         gen_elems( int pos ) const = 0;//����Ԫ��ֱ��posλ����
	bool                 check_integrity( int pos ) const; //�б�pos�Ƿ�Ϊ��Чλ��
	const static int     _max_elems = 1024;//������󳤶�
	int                  _length;//���г���
	int                  _beg_pos;//���п�ʼλ��
	vector<int>          &_relems;//�������е�����
};

int num_sequence::
elem( int pos ) const {
	if ( !check_integrity( pos ) )
		return 0;

	return _relems[ pos - 1 ];
}

ostream& num_sequence::
print( ostream &os ) const {
	int elem_pos = _beg_pos;//��ӡ�����ĵ�һ�����Ķ�Ӧ��λ��
	int end_pos = elem_pos + ( _length - 1 );//��ӡ���������һ�����Ķ�Ӧ��λ��

	if ( end_pos > _relems.size() )
		gen_elems( end_pos );

	while ( elem_pos <= end_pos )
		os << _relems[( elem_pos++ ) - 1] << " ";

	return os;
}

bool num_sequence::
check_integrity( int pos ) const {
	if ( pos <= 0 || pos > _max_elems ) {
		cerr << "!! Invalid position: " << pos << ". Cannot honor request!\n";
		return false;
	}

	if ( pos > _relems.size() )
		gen_elems( pos );

	return true;
}

ostream& operator<< ( ostream &os, const num_sequence &ns ) { return ns.print(); }
