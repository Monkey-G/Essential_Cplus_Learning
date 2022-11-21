#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

typedef vector<string> svec;//宏定义svec

void population_map( ifstream&, map<string, svec>& );
void usr_check( const map<string, svec>& );
void display( const map<string, svec>&, ostream& );

int main() {

	ifstream ifile("E:\\手撕代码\\template\\template3_6.txt");
	//姓名集合文件里每行有不定数量的人，但都是以姓氏开头，后续空格接名字，
	//名字间以逗号（英文）隔开，每行的最后一个名字后没有逗号
	ofstream ofile("E:\\手撕代码\\template\\template3_6_settle.txt");
	if (!ifile || !ofile) {
		cerr << "Unable to open file -- bailing out!\n";
		return -1;
	}

	map<string, svec> families;//定义一个初始map
	population_map(ifile, families);//处理map

	string usr_answer;
	cout << "Would U like to check some families?(Y/y or N/n) ";
	cin >> usr_answer;
	while (usr_answer == "Y" || usr_answer == "y") {
		system("cls");

		usr_check( families );

		cout << "Would U like to check more?(Y/y or N/n) ";
		cin >> usr_answer;
	}//用户查询
	system("cls");

	cout << "Would U like to get the settled data?(Y/y or N/n) ";
	cin >> usr_answer;
	while (usr_answer == "Y" || usr_answer == "y") {
		system("cls");
		display( families, cout);
	}//输出处理后的map(不知道为什么cout老是闪烁，ofile也读取了很多次，有待解决)
}

void population_map( ifstream& nameFile, map<string, svec>& families ) {
	string textline;//家族姓氏
	while ( getline(nameFile, textline) ) {//getline()可以读取文件的一行内容
		string name;//姓名
		string first_name;//姓
		string::size_type
			pos = 0, pos1 = 0, prev_pos = 0,
			text_size = textline.size();

		//将每个人的姓和名作为单字抽取出来
		while ((pos = textline.find_first_of( ',', pos )) != string::npos) {
			pos1 = textline.find_first_of( ' ', pos1 );
			first_name = textline.substr(prev_pos, (pos1++)- prev_pos);
			if (!families.count(first_name)) {
				families[first_name] = {};
				families[first_name].push_back(textline.substr(pos1, pos-pos1) );
			}
			else
				families[first_name].push_back(textline.substr(pos1, pos-pos1));
			prev_pos = ++pos;
			pos1 = pos;
		}

		//处理每行中最后一个人
		if (pos == string::npos) {
			pos1 = textline.find_first_of(' ', pos1);
			first_name = textline.substr(prev_pos, (pos1++) - prev_pos);
			if (!families.count(first_name)) {
				families[first_name] = {};
				families[first_name].push_back(textline.substr(pos1, pos - pos1));
			}
			else
				families[first_name].push_back(textline.substr(pos1, pos - pos1));
		}
	}

}

void usr_check( const map<string, svec>& families ) {
	string search_family;

	cout << "Please enter the family to search:";
	cin >> search_family;

	map<string, svec>::const_iterator it;//it指向的为map中的key，其it++会指向下一个key，与value无关
	if ((it = families.find(search_family)) != families.end()) {
		cout << "Found! The " << it->first << " has " << it->second.size() << " children: ";
		vector<string>::const_iterator iter = it->second.begin(),//这里写嵌套时不可以用svec代替vector<string>
			                    end_of_iter = it->second.end();
		while (iter != end_of_iter) {
			cout << *iter << " ";
			++iter;
		}
		cout << endl;
	}
	else
		cout << "NotFound! The " << it->first << " isn't currently entered.\n ";
}

void display( const map<string, svec>& families, ostream &os ) {//ostream &os前不能加const 
	map<string, svec>::const_iterator it = families.begin(),
		                       end_of_it = families.end();

	while ( it != end_of_it ) {
		if ( it -> second.empty() )
			os << "The " << it->first << " family has no children\n " << endl;
		else {
			os << "The " << it->first << " has " << it->second.size() << " children: ";
			vector<string>::const_iterator iter = it->second.begin(),//这里写嵌套时不可以用svec代替vector<string>
				                    end_of_iter = it->second.end();
			while (iter != end_of_iter) {
				os << *iter << " ";
				++iter;
			}
			os << endl;
		}
		++it;
	}
}