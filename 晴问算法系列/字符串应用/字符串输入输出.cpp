#include <iostream>
#include <string>
using namespace std;

const int MAX_LEN = 51;     //最后一个是特殊符号的下标，所以多加一个(比如'\n')
char str[MAX_LEN];      //定义一个字符串数组，即str数组中每个元素的字符类型应该是char类型
 
//   方式一，直接利用getline函数进行整行输入
void method1()
{
    string s;
    getline(cin, s);        //s可以作为string类型
    cout << s << endl;
    cout <<s.substr(0, 10) << endl;     //切片工具
}

//方式二，利用cin类当中的getline来按一行接收字符
void method2()
{
    cin.getline(str, MAX_LEN);      //仅仅接收前50个字符，该函数当中str得为char类型
    cout << str <<endl;
}

//方式三，利用C++中的fgets()函数
void method3()
{
    fgets(str, MAX_LEN, stdin);         //第三个参数是文件指针，默认stdin，但是该函数会将换行符也读进去(因此需要处理'\n')
    cout << str;
}

int main()
{
    method1();
    method2();
    method3();
    return 0;
}


