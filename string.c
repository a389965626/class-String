///
/// @file    string.c
/// @author  a389965626(389965626@qq.com)
/// @date    2018-06-06 19:30:10
///
//现一个自定义的String类，保证main函数对正确执行
#include <iostream>
#include <string.h>
using std::cout;
using std::endl;
//string类
class String
{
	public:
		String();
		String(const char *pstr);
		String(const String & rhs);
		String & operator=(const String & rhs);
		~String();

		void print();

	private:
		char *_pstr;
};
//默认构造函数
String::String()
{
	_pstr=new char[1];
	*_pstr='\0';//默认构造函数，定义一个空字符串
}
//带参构造函数
String::String(const char *pstr)
{
	if(pstr==NULL)
	{
		_pstr=new char[1];
		*_pstr='\0';
	}
	else
	{
		_pstr=new char[strlen(pstr)+1];//申请空间
		strcpy(_pstr,pstr);//拷贝字符串的内容
	}
}
//复制构造函数
String::String(const String &rhs)
{
	int len=strlen(rhs._pstr);
	_pstr=new char[len+1];
	strcpy(_pstr,rhs._pstr);
}
//赋值函数=，运算符的重载operator关键字：operator 运算符
String &String::operator=(const String & rhs)
{
	if(this==&rhs)   //如果本来就是同一对象，则不用赋值=
	{
		return *this;//直接返回本对象的指针
	}
	//否则表明不是同一个对象，应该进行赋值

	//赋值之前应该先清空本对象的数据成员
	delete [] _pstr;
	//然后再进行赋值
	int len=strlen(rhs._pstr);
	_pstr=new char[len+1];//申请内存
	strcpy(_pstr,rhs._pstr);
	return *this; //返回本对象的引用
}
//析构函数
String::~String()
{
	delete [] _pstr;//delet 指针成员，防止内存泄漏
}
//print函数
void String::print()
{
	cout << _pstr << endl;
}
int main(void)
{
	String str1;
	str1.print();

	String str2 = "Hello,world";
	String str3("wangdao");

	str2.print();		
	str3.print();	

	String str4 = str3;
	str4.print();

	str4 = str2;
	str4.print();

	return 0;
}
