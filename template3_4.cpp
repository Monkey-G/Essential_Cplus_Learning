#include <iostream>
#include <map>
#include <string>
#include <set>
#include <fstream>

using namespace std;

void initialize_exclusion_set( set<string>&, string istring );//由用户初始化排除字集
void map_string( map<string,int>&, const set<string>&, ifstream& );
void usr_check( const map<string, int>& );
void display_count( const map<string, int>&, ostream& );

int main() {

	ifstream ifile( "E:\\手撕代码\\template\\template3_4.txt" );
	ofstream ofile("E:\\手撕代码\\template\\template3_4_map.txt");
	if ( !ifile || !ofile) {
		cerr << "Unable to open file -- bailing out!\n";
		return -1;
	}

	string usr_answer;
	set<string> exclusion_set;
	cout << "Would U like to enter some words that U do not want to count?(Y/y or N/n) ";
	cin >> usr_answer;
	while ( usr_answer == "Y" || usr_answer == "y" ) {
		system("cls");

		cout << "Please enter the words U do not want to count: ";

		string exstring;
		cin >> exstring;
		initialize_exclusion_set( exclusion_set, exstring );

		cout << "Would U like to enter more words?(Y/y or N/n) ";
		cin >> usr_answer;
	}//排除字集定义完成
	system("cls");

	map<string, int> word_count;
	map_string( word_count, exclusion_set, ifile );

	cout << "Would U like to check the word_count if it have some words U wanna?(Y/y or N/n) ";
	cin >> usr_answer;
	while (usr_answer == "Y" || usr_answer == "y") {
		system("cls");
		usr_check(word_count);
		cout << "Would U like to check more words?(Y/y or N/n) ";
		cin >> usr_answer;
	}
	system("cls");

	display_count(word_count, ofile);
}

void initialize_exclusion_set( set<string> &exset, string istring ) {
	exset.insert(istring);//不能用push_back
}

void map_string( map<string, int> &word_count, const set<string> &exset, ifstream &ifile ) {
	string word;
	while (ifile >> word) {
		if (!exset.count(word))
			word_count[word]++;
	}
}

void usr_check(const map<string, int> &word_map) {
	string search_word;

	cout << "Please enter a word to search:";
	cin >> search_word;

	map<string, int>::const_iterator it;
	if ((it = word_map.find(search_word)) != word_map.end())
		cout << "Found! " << it->first << " occurs " << it->second << " times.\n";
	else
		cout << "NotFound!" << search_word << " was not found in the text.\n";
}

void display_count(const map<string, int>& word_map, ostream& os) {
	map<string, int>::const_iterator it = word_map.begin(),
	                          end_of_it = word_map.end();
	while (it != end_of_it) {
		os << "string: " << it->first << " times: " << it->second << endl;
		it++;
	}
	os << endl;
}