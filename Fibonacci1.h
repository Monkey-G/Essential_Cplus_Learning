#include"num_sequence1.h"

class Fibonacci : public num_sequence {
public:
	Fibonacci(int len = 1, int beg_pos = 1);//constructor������Ĭ�ϳ��ȺͿ�ʼλ�þ�Ϊ1
	//������Fibonacci��destructor

	const char*          who_am_i() const { return "Fibonacci"; }//��������ΪFibonacci

protected:
	void                 gen_elems( int pos ) const;//����Ԫ��ֱ��posλ����
	//!��̬��Ա������������ʵ������֮ǰ���죬���Ի��ڱ����ڹ���,
	//! �������_elems�Ǳ���Ҫ��ʼ������class�����ʼ��static vector<int>   _elems = {};
	//! �����ں���ǰ�߼�һ��inline��ʾΪ�����������ڵ�һ�α��뵽���������ʱ��ͻ��ʼ������C++ std17��֧��������ԣ�
	//! ����û�г�ʼ���Ļ����Ͳ�������ڴ棬
	//! ���Ҿ�̬��Ա������������๲��ģ��ڱ����ʱ��ͻᴴ����
	//! �����������϶��Ҳ�������˻�������
	//! �����Ժ�ˮƽ��ȥ���ٶ࿴����
	static vector<int>   _elems;//����Fibonacci���е�����
};

//!һ��Ҫ�ж�num_sequence constructor�ĵ��ò���������num_sequence��֪��������һ�������е�constructor
inline Fibonacci::
Fibonacci(int len, int beg_pos)
	: num_sequence( len, beg_pos, _elems ){}

vector<int> Fibonacci::_elems = {};

void Fibonacci::
gen_elems( int pos ) const {
	if ( _elems.empty() ) {//��ʼ��
		_elems.push_back( 1 ); _elems.push_back( 1 );
	}

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

