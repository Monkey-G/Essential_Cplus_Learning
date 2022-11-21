#include"LIFO_Stack.h"

void peek( Stack& st, int index ) {
	cout << endl;
	string t;
	if ( st.peek(index, t) )
		cout << "peek: " << t;
	else cout << "peek failed!";
	cout << endl;
}

int main() {
	LIFO_Stack st;
	string str;

	while ( cin >> str && !st.full() )
		st.push( str );

	cout << "\n" << "About to call peek() with LIFO_Stack (the last string):" << endl;
	peek( st, st.size() - 1 );
	cout << st;

	Peekback_Stack pst;
	
	while ( !st.empty() ) {
		string t;
		if ( st.pop( t ) )
			pst.push( t );//将st的值倒序传入pst
	}

	cout << "\n" << "About to call peek() with Peekback_Stack (the last string): " << endl;
	peek( pst, pst.size() - 1 );
	cout << pst;
}