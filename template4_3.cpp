//����ԭ�����İ汾

#include<string>
#include<map>
#include<iostream>

using namespace std;

class UserProfile {
public:
	enum UserLevel { Beginner, Intermediate, Advanced, Guru };//�ȼ�����

	//����constructor
	//default memberwise initialization �� default memberwise copy ���㹻����
	//�����������copy constructor �� copy assignment operator
	//Ҳ����Ҫdestructor
	UserProfile( string login, UserLevel = Beginner );//UserLevel = Beginner��������UserLevelһ��Ĭ�ϲ�����ʼֵ�ģ���Ӱ�������ʼ��������������������UserProfile anna("Annal");����䣬��UserLevel��һ��Ĭ�ϵĲ���ΪBeginner
	UserProfile();//����Ĭ���û��ĵȼ��͵�¼���ƣ�guest�����������ֲ�ͬ��Ĭ���û�����guest���id��

	bool operator == ( const UserProfile& );//�������
	bool operator != ( const UserProfile &rhs );// ��������

	//�û�����
	string login() const { return _login; }//��¼��¼
	string user_name() const { return _user_name; }//�û�������ԭ�������ûɶ����
	int login_count() const { return _times_logged; }//�������
	int guess_count() const { return _guesses; }//�¹�����
	int guess_correct() const { return _correct_guesses; }//�¶Դ���
	double guess_average() const;//�¶԰ٷֱ�
	string level() const;//�ȼ�

	//�����û�����
	void reset_login( const string &val ) { _login = val; }//���õ�¼��¼
	void reset_user_name( const string& val ) { _user_name = val; }//�����û�����
	void reset_login_count( int val ) { _times_logged = val; }//���õ������
	void reset_guess_count( int val ) { _guesses = val; }//���ò¹�����
	void reset_guess_correct( int val ) { _correct_guesses = val; }//���ò¶Դ���
	void reset_level( const string& );//���õȼ�
	void bump_login_count( int cnt = 1 ) { _times_logged += cnt; }
	void bump_guess_count( int cnt = 1 ) { _guesses += cnt; }
	void bump_guess_correct( int cnt = 1 ) { _correct_guesses += cnt; }

private://һЩclass�ⲻ��Ҫ�õ�����Ӧ����private�У������ӵĺ������御������class���ֹ����ӷ��
	string _login;
	string _user_name;
	int _times_logged;
	int _guesses;
	int _correct_guesses;
	UserLevel _user_level;//!_user_level��������һ������,������Beginner֮���string

	static map<string, UserLevel> _level_map;//�����û��ȼ���map����ʹ���ж�β�ѯĳһ�û��ȼ�����Ҫ���ʵʱ����
	static void init_level_map();//_level_map�ĳ�ʼ��������class�ⲻ��Ҫʹ�øú������ʷ���private��
};

inline UserProfile::
UserProfile(string login, UserLevel level)//?���������Ҳ���Ǻܶ�������������ʹ�� enum class ��ֹʹ�� enum ���¶�ȫ�������ռ��е���Ⱦ��
	: _login(login), _user_level(level),
	_times_logged(1), _guesses(0), _correct_guesses(0) {}//!���಻��Ҫ��;������һ���պ���

#include <cstdlib>//��ΪҪ�õ�_itoa()

inline UserProfile::
UserProfile()
	: _login("guest"), _user_level(Beginner),
	_times_logged(1), _guesses(0), _correct_guesses(0) {

	//����Ϊ��̬�ֲ��������ڱ���ʱ����ֵ�ģ���ֻ����ֵһ�Σ��ڳ�������ʱ�����г�ֵ���Ժ���ÿ�ε��ú���ʱ�Ͳ������¸���ֵ�����Ǳ����ϴκ������ý���ʱ��ֵ��
	static int id = 0;//����Ϊstatic���Ա�֤id������������������ʧ�������ֺ����������ֵ��ע�����ٴε����������ϴκ����������ֵ�������ٴθ�ֵ
	char buffer[16];//buffer������Դ���15���ַ������ȵ�char��buffer�����һλҪ����'\0'����Ϊchar����ĩβҪ��'\0'�����������Զ�Ӧguest0~guest(10^16-1)

	//_itoa()��C��׼�����ṩ�ĺ�����������ת��Ϊ��Ӧ��ASCII�ַ�����ʽ���Լ���guest���
	//char itoa(int value, char str, int base);
	//int value ��ת����������char string ת���󴢴���ַ����飬int base ת������������2,8,10,16 ���Ƶȣ���СӦ��2-36֮�䡣
    #pragma warning(disable:4996) //������������ΪVS������_itoa������������ʾ����Ӧ��C4996��������תΪ����
	_itoa( id++, buffer, 10 );
    #pragma warning(default:4996) //��ʾ����Ӧ��C4996��������תΪ����Ĳ�����ԭΪ����

	_login += buffer;
}

inline bool UserProfile::
operator == (const UserProfile &rhs) {
	if ( _login == rhs._login && _user_name == rhs._user_name )//������*this == rhs��Ϊ�ж�,������Ҳ������
		return true;
	return false;
}

inline bool UserProfile::
operator != (const UserProfile &rhs) { return !( *this == rhs ); }

inline double UserProfile::
guess_average() const {
	return _guesses
		? double(_correct_guesses) / double(_guesses) * 100
		: 0.0;
}

inline string UserProfile::
level() const {
	static string _level_table[] = { "Beginner", "Intermediate", "Advanced", "Guru" };
	return _level_table[_user_level];
}

inline void UserProfile::
reset_level(const string& level) {
	map<string, UserLevel>::iterator it;
	if (_level_map.empty())
		init_level_map();

	_user_level = ((it = _level_map.find(level)) != _level_map.end())
		? it->second
		: Beginner;
}

map<string, UserProfile::UserLevel> UserProfile::_level_map;//��Ϊɶ��Ҫ����һ��,���˲²�Ӧ������Ϊ�������Ļ�������class��_level_map����Ϊstatic�����Բ��ܱ������ʣ���������������ߣ�����Ҫ����һ�β���ʵ�ֺ����Ķ���

void UserProfile::
init_level_map() {
	_level_map["Beginner"] = Beginner;
	_level_map["Intermediate"] = Intermediate;
	_level_map["Advanced"] = Advanced;
	_level_map["Guru"] = Guru;
}

ostream& //���������
operator << (ostream& os, const UserProfile& rhs) {
	//�����ʽ:monkey Beginner 2 10 1 10%
	os << rhs.login() << " "
		<< rhs.level() << " "
		<< rhs.login_count() << " "
		<< rhs.guess_count() << " "
		<< rhs.guess_correct() << " "
		<< rhs.guess_average() << endl;
	return os;
}

istream& //����������
operator >> ( istream& is, UserProfile& rhs ) {
	//�����ʽ:monkey Beginner 2 10 1 
	//�ݲ����������
	string login, level;
	int login_count, guess_count, guess_correct;

	is >> login >> level >> login_count >> guess_count >> guess_correct;

	rhs.reset_login( login );
	rhs.reset_level( level );
	rhs.reset_login_count( login_count );
	rhs.reset_guess_count( guess_count );
	rhs.reset_guess_correct( guess_correct );
	
	return is;
}

int main() {
	UserProfile anon1;
	cout << anon1;

	UserProfile anon2;
	cout << anon2;

	UserProfile anna1("Annal");
	cout << anna1;

	UserProfile anna2("Annal", UserProfile::Guru);
	cout << anna2;

	anna2.reset_guess_count(27);//��anna2.bump_guess_count(27);һ����������Ҳ������
	anna2.reset_guess_correct(25);//��ͬ��
	anna2.bump_login_count();
	cout << anna2;

	cin >> anon1;//robin Intermediate 1 8 3
	cout << anon1;
}