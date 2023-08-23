#include "String.h"
#include "shared_ptr.h"
using namespace std;

int main() {
    const char* str = "I love you";
    String s1(str);
    cout << "String中的字符串为：" << s1.c_str() << "\n"
    << "字符串的长度：" << s1.size() << endl;

    String s2(s1);
    cout << "String中的字符串为：" << s2.c_str() << "\n"
    << "字符串的长度：" << s2.size() << endl;

    String s3("get out!");
    cout << "String中的字符串为：" << s3.c_str() << "\n"
    << "字符串的长度：" << s3.size() << endl;

    s3 = s1;
    cout << "String中的字符串为：" << s3.c_str() << "\n"
    << "字符串的长度：" << s3.size() << endl;

    // 再简单测试一下自己写的智能指针
    {
        SharedPtr<String> s_ptr(new String("a test."));
        cout << "String中的字符串为：" << s_ptr->c_str() << "\n"
        << "字符串的长度：" << s_ptr->size() << endl;
    }

    return 0;
}