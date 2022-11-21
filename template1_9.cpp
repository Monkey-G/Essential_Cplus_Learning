#include <iostream>
#include <fstream>
#include <algorithm>//���������㷨sort()
#include <string>
#include <vector>
using namespace std;

int main() {

	ifstream in_file("E:\\��˺����\\template\\template1_9_store.txt");
	if (!in_file) {
		cerr << "Unable to open the input file\n"; return -1;
	}

	ofstream out_file("E:\\��˺����\\template\\template1_9_sort.txt");
	if (!out_file) {
		cerr << "Unable to open the output file\n"; return -2;
	}

	string word;
	vector <string> text;
	while (in_file >> word) {
		text.push_back(word);
	}

	int ix;//
	cout << "The stored text: \n";
	for (ix = 0; ix < text.size(); ++ix) {
		cout << text[ix] << " " ;
	}
	cout << endl;

	sort(text.begin(), text.end());
	//��������233����3ǰ�ߵ����⣬����Ϊ�ַ�������ʱĬ�ϸ�λ�������ж�233��3�����Ⱥ�ʱ��ֻ����233��3�����λ��2��3��
	//ASCII���е������Ⱥ󣬹�233����3ǰ��

	cout << "The sorted text: \n";
	for (ix = 0; ix < text.size(); ++ix) {
		out_file << text[ix] << " ";
		cout << text[ix] << " ";
	}
	cout << endl;

	return 0;
}