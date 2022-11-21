#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

typedef vector<string> svec;//�궨��svec

void population_map( ifstream&, map<string, svec>& );
void usr_check( const map<string, svec>& );
void display( const map<string, svec>&, ostream& );

int main() {

	ifstream ifile("E:\\��˺����\\template\\template3_6.txt");
	//���������ļ���ÿ���в����������ˣ������������Ͽ�ͷ�������ո�����֣�
	//���ּ��Զ��ţ�Ӣ�ģ�������ÿ�е����һ�����ֺ�û�ж���
	ofstream ofile("E:\\��˺����\\template\\template3_6_settle.txt");
	if (!ifile || !ofile) {
		cerr << "Unable to open file -- bailing out!\n";
		return -1;
	}

	map<string, svec> families;//����һ����ʼmap
	population_map(ifile, families);//����map

	string usr_answer;
	cout << "Would U like to check some families?(Y/y or N/n) ";
	cin >> usr_answer;
	while (usr_answer == "Y" || usr_answer == "y") {
		system("cls");

		usr_check( families );

		cout << "Would U like to check more?(Y/y or N/n) ";
		cin >> usr_answer;
	}//�û���ѯ
	system("cls");

	cout << "Would U like to get the settled data?(Y/y or N/n) ";
	cin >> usr_answer;
	while (usr_answer == "Y" || usr_answer == "y") {
		system("cls");
		display( families, cout);
	}//���������map(��֪��Ϊʲôcout������˸��ofileҲ��ȡ�˺ܶ�Σ��д����)
}

void population_map( ifstream& nameFile, map<string, svec>& families ) {
	string textline;//��������
	while ( getline(nameFile, textline) ) {//getline()���Զ�ȡ�ļ���һ������
		string name;//����
		string first_name;//��
		string::size_type
			pos = 0, pos1 = 0, prev_pos = 0,
			text_size = textline.size();

		//��ÿ���˵��պ�����Ϊ���ֳ�ȡ����
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

		//����ÿ�������һ����
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

	map<string, svec>::const_iterator it;//itָ���Ϊmap�е�key����it++��ָ����һ��key����value�޹�
	if ((it = families.find(search_family)) != families.end()) {
		cout << "Found! The " << it->first << " has " << it->second.size() << " children: ";
		vector<string>::const_iterator iter = it->second.begin(),//����дǶ��ʱ��������svec����vector<string>
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

void display( const map<string, svec>& families, ostream &os ) {//ostream &osǰ���ܼ�const 
	map<string, svec>::const_iterator it = families.begin(),
		                       end_of_it = families.end();

	while ( it != end_of_it ) {
		if ( it -> second.empty() )
			os << "The " << it->first << " family has no children\n " << endl;
		else {
			os << "The " << it->first << " has " << it->second.size() << " children: ";
			vector<string>::const_iterator iter = it->second.begin(),//����дǶ��ʱ��������svec����vector<string>
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