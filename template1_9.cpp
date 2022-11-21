#include <iostream>
#include <fstream>
#include <algorithm>//包含泛型算法sort()
#include <string>
#include <vector>
using namespace std;

int main() {

	ifstream in_file("E:\\手撕代码\\template\\template1_9_store.txt");
	if (!in_file) {
		cerr << "Unable to open the input file\n"; return -1;
	}

	ofstream out_file("E:\\手撕代码\\template\\template1_9_sort.txt");
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
	//遇到类似233排在3前边的问题，是因为字符串排序时默认高位排序，在判断233和3排序先后时，只考虑233和3中最高位即2和3在
	//ASCII表中的排序先后，故233排在3前边

	cout << "The sorted text: \n";
	for (ix = 0; ix < text.size(); ++ix) {
		out_file << text[ix] << " ";
		cout << text[ix] << " ";
	}
	cout << endl;

	return 0;
}