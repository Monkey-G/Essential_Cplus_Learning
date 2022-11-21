#include<string>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

class Stack {//member function����class�ڶ���������ڳ����ڶ���
public:
	bool push( const string& );
	bool pop( string & );//pop��peek�Ὣ��ɾ�������Ͳ鿴�������
	bool peek( string& );
	bool find( const string& );
	int count( const string& );

	bool empty() const { return _stack.empty(); }
	bool full() const { return _stack.size() == _stack.max_size(); }
	int size() const { return _stack.size(); }
	string head_string() { return _stack.front(); }
	string tail_string() { return _stack.back(); }

	void display_total_string() {
		vector<string>::iterator it = _stack.begin(),
			end_of_it = _stack.end();
		while (it != end_of_it) {
			cout << *it << " ";
			++it;
		}
	}
private:
	vector<string> _stack;
};