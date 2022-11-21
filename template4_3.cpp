//根据原书做的版本

#include<string>
#include<map>
#include<iostream>

using namespace std;

class UserProfile {
public:
	enum UserLevel { Beginner, Intermediate, Advanced, Guru };//等级设置

	//两类constructor
	//default memberwise initialization 和 default memberwise copy 已足够所需
	//不必另外设计copy constructor 或 copy assignment operator
	//也不需要destructor
	UserProfile( string login, UserLevel = Beginner );//UserLevel = Beginner是用来给UserLevel一个默认参数初始值的，不影响后续初始化，而且这样可以运行UserProfile anna("Annal");的语句，而UserLevel有一个默认的参数为Beginner
	UserProfile();//处理默认用户的等级和登录名称（guest），并能区分不同的默认用户（在guest后加id）

	bool operator == ( const UserProfile& );//相等运算
	bool operator != ( const UserProfile &rhs );// 不等运算

	//用户数据
	string login() const { return _login; }//登录记录
	string user_name() const { return _user_name; }//用户姓名，原例里这个没啥屌用
	int login_count() const { return _times_logged; }//登入次数
	int guess_count() const { return _guesses; }//猜过次数
	int guess_correct() const { return _correct_guesses; }//猜对次数
	double guess_average() const;//猜对百分比
	string level() const;//等级

	//重置用户数据
	void reset_login( const string &val ) { _login = val; }//重置登录记录
	void reset_user_name( const string& val ) { _user_name = val; }//重置用户姓名
	void reset_login_count( int val ) { _times_logged = val; }//重置登入次数
	void reset_guess_count( int val ) { _guesses = val; }//重置猜过次数
	void reset_guess_correct( int val ) { _correct_guesses = val; }//重置猜对次数
	void reset_level( const string& );//重置等级
	void bump_login_count( int cnt = 1 ) { _times_logged += cnt; }
	void bump_guess_count( int cnt = 1 ) { _guesses += cnt; }
	void bump_guess_correct( int cnt = 1 ) { _correct_guesses += cnt; }

private://一些class外不需要用到函数应放于private中，而复杂的函数定义尽量放于class外防止过于臃肿
	string _login;
	string _user_name;
	int _times_logged;
	int _guesses;
	int _correct_guesses;
	UserLevel _user_level;//!_user_level本质上是一个索引,并不是Beginner之类的string

	static map<string, UserLevel> _level_map;//储存用户等级的map，在使用中多次查询某一用户等级不需要多次实时计算
	static void init_level_map();//_level_map的初始化函数，class外不需要使用该函数，故放在private中
};

inline UserProfile::
UserProfile(string login, UserLevel level)//?这个警告我也不是很懂啊，更倾向于使用 enum class 防止使用 enum 导致对全局命名空间中的污染。
	: _login(login), _user_level(level),
	_times_logged(1), _guesses(0), _correct_guesses(0) {}//!这类不需要“;”，是一个空函数

#include <cstdlib>//因为要用到_itoa()

inline UserProfile::
UserProfile()
	: _login("guest"), _user_level(Beginner),
	_times_logged(1), _guesses(0), _correct_guesses(0) {

	//！因为静态局部变量是在编译时赋初值的，且只赋初值一次，在程序运行时它已有初值。以后在每次调用函数时就不再重新赋初值，而是保留上次函数调用结束时的值。
	static int id = 0;//声明为static可以保证id并不会因函数调用完消失，而保持函数调用完的值，注意在再次调用是沿用上次函数调用完的值，而非再次赋值
	char buffer[16];//buffer创造可以储存15个字符串长度的char，buffer的最后一位要留给'\0'，因为char数组末尾要以'\0'结束，即可以对应guest0~guest(10^16-1)

	//_itoa()是C标准库所提供的函数，会整数转换为对应的ASCII字符串形式，以加在guest后边
	//char itoa(int value, char str, int base);
	//int value 被转换的整数，char string 转换后储存的字符数组，int base 转换进制数，如2,8,10,16 进制等，大小应在2-36之间。
    #pragma warning(disable:4996) //必须加这个，因为VS已弃用_itoa（）函数，表示将对应的C4996错误无视转为警告
	_itoa( id++, buffer, 10 );
    #pragma warning(default:4996) //表示将对应的C4996错误无视转为警告的操作还原为错误

	_login += buffer;
}

inline bool UserProfile::
operator == (const UserProfile &rhs) {
	if ( _login == rhs._login && _user_name == rhs._user_name )//？不能*this == rhs作为判断,理由我也不到啊
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

map<string, UserProfile::UserLevel> UserProfile::_level_map;//？为啥又要声明一次,个人猜测应该是因为不声明的话由于在class里_level_map声明为static，所以不能被外界访问，而函数定义在外边，所以要声明一次才能实现后续的定义

void UserProfile::
init_level_map() {
	_level_map["Beginner"] = Beginner;
	_level_map["Intermediate"] = Intermediate;
	_level_map["Advanced"] = Advanced;
	_level_map["Guru"] = Guru;
}

ostream& //输出流重载
operator << (ostream& os, const UserProfile& rhs) {
	//输出格式:monkey Beginner 2 10 1 10%
	os << rhs.login() << " "
		<< rhs.level() << " "
		<< rhs.login_count() << " "
		<< rhs.guess_count() << " "
		<< rhs.guess_correct() << " "
		<< rhs.guess_average() << endl;
	return os;
}

istream& //输入流重载
operator >> ( istream& is, UserProfile& rhs ) {
	//输出格式:monkey Beginner 2 10 1 
	//暂不做错误检验
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

	anna2.reset_guess_count(27);//？anna2.bump_guess_count(27);一样，理由我也不到啊
	anna2.reset_guess_correct(25);//？同上
	anna2.bump_login_count();
	cout << anna2;

	cin >> anon1;//robin Intermediate 1 8 3
	cout << anon1;
}