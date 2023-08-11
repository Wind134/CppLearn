#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(string str1, string str2){
    return str1.length() > str2.length();   //按字符串长度从长到短排列，自定义排列方式
}

int main(){
    string str[3] = {"nnnn", "cc", "aaa"};
    sort(str, str + 3, cmp);    // 这里也可写成lambda表达式方式
    for (int i = 0; i < 3; i++)
        cout << str[i] << endl;

    return 0;
}