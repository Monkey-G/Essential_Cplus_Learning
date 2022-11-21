#include<vector>
#include"num_sequence.h"

class Fibonacci : public num_sequence {
public:
	Fibonacci( int len = 1, int beg_pos = 1 )
		: _length( len ), _beg_pos( beg_pos ) {}//constructor��Ĭ�ϳ��ȺͿ�ʼλ�þ�Ϊ1
	//������Fibonacci��destructor

	int                  elem( int pos ) const; //����posλ����Fibonacci����
	const char*          who_am_i() const { return "Fibonacci"; }//��������ΪFibonacci
	ostream&             print( ostream &os = cout ) const;//��ӡ����Fibonacci
	int                  length() const { return _length; }//�������г���
	int                  beg_pos() const { return _beg_pos; }//�������п�ʼλ��

protected:
	void                 gen_elems( int pos ) const;//����Ԫ��ֱ��posλ����
	int                  _length;//����
	int                  _beg_pos;//���п�ʼλ��

	//!��̬��Ա������������ʵ������֮ǰ���죬���Ի��ڱ����ڹ���,
	//! �������_elems�Ǳ���Ҫ��ʼ������class�����ʼ��static vector<int>   _elems = {};
	//! �����ں���ǰ�߼�һ��inline��ʾΪ�����������ڵ�һ�α��뵽���������ʱ��ͻ��ʼ������C++ std17��֧��������ԣ�
	//! ����û�г�ʼ���Ļ����Ͳ�������ڴ棬
	//! ���Ҿ�̬��Ա������������๲��ģ��ڱ����ʱ��ͻᴴ����
	//! �����������϶��Ҳ�������˻�������
	//! �����Ժ�ˮƽ��ȥ���ٶ࿴����
	static vector<int>   _elems;//����Fibonacci���е�����
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
	int elem_pos = _beg_pos;//��ӡ�����ĵ�һ�����Ķ�Ӧ��λ��
	int end_pos = elem_pos + (_length - 1);//��ӡ���������һ�����Ķ�Ӧ��λ��

	if ( end_pos > _elems.size() )
		Fibonacci::gen_elems( end_pos );

	while ( elem_pos <= end_pos )
		os << _elems[ (elem_pos++) - 1 ] << " ";

	return os;
}

void Fibonacci::
gen_elems( int pos ) const {
	if ( _elems.empty() ) {//��ʼ��
		_elems.push_back( 1 ); _elems.push_back( 1 );}

	if ( _elems.size() <= pos ) {//�����ܴ���_elems.size() = 1 ���������Ϊ�ڶ���_elemsʱ�����ǿյģ������ڿ�ʼ������ֵ֮��һ���ᾭ�������ĳ�ʼ��
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

