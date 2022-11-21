#include<iostream>

using namespace std;

class LibMat {//ͼ��ݹ���
public:
	LibMat() { cout << "LibMat::LibMat() default constructor!\n"; }//default constructor

	virtual ~LibMat(){ cout << "LibMat::~LibMat() destructor!\n"; }//destructor

	virtual void print() const {
		cout << "LibMat::print() -- I am a LibMat object!" << endl; }
};

class Book : public LibMat {//��
public:
	Book() 
	: _title("unknown"), _author("unknown") { 
		cout << "Book::Book() default constructor!\n"; }//default constructor

	Book(const string& title, const string& author)
		: _title(title), _author(author) {
		cout << "Book::Book(" << _title << ", " << _author << ") constructor!\n";}//constructor

	virtual ~Book() { cout << "Book::~Book() destructor!\n"; }//destructor

	virtual void print() const {
		cout << "Book::print() -- I am a Book object!\n"
			<< "My title is: " << _title << ".\n"
			<< "My author is: " << _author << ".\n" << endl;
	}

	const string& title() const { return _title; }
	const string& author() const { return _author; }

protected:
	string _title;//����
	string _author;//����
};

void print(const LibMat& mat) {
	cout << "in global print(): about to print mat.print()\n";
	mat.print();
}

int main() {
	//��������ȳ�ʼ�����е�class��Ȼ����ִ�к��������ڽ�������class
	LibMat mat;
	Book book;
	Book book1( "The Castle", "Franz Kafka" );

	print(mat);
	print(book);
	print(book1);
}