#include <iostream>
#include <string>
using namespace std;


void Count_punct()
{
    string s("Hello World!!!");
    decltype (s.size()) punct_cnt = 0;  //使得punct的类型与size()函数的返回值类型一致
    for (auto c : s)
        if (ispunct(c))  ++punct_cnt;
    cout <<"在" << s << "中有" << punct_cnt << "个标点符号!" << endl;
}

void ChangeChar()
{
    string s("Hello World!!!");
    for (auto &c : s)   c = toupper(c);     //应该能理解为何要加引用吧,toupper函数功能为
    //转化为大写！
    cout << s << endl;
}

int main()
{
    string str("some string");          //空格也会同步打印出来
    string str1("some string"); 
    Count_punct ();
    ChangeChar();
    for (auto c : str)  cout << c << "  ";
    cout << endl;
    for (decltype(str1.size()) index = 0; index != str.size() && !isspace(str1[index]);
    ++index)    str1[index] = toupper(str1[index]);
    cout << str1 << endl;
}