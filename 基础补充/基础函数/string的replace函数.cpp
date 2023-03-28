#include <iostream>
#include <string>
using namespace std;

int main () {
    string s1, s2;
    int k, len;
    cin >> s1 >> k >> len >> s2;
    string s3 = s1.replace(k, len, s2); // 需不需要保证s2的长度？
    /* 经过测试，发现的是，如果s2的长度短于len，len多出来的长度会置空
    如果s2的长度长于len，还是会将s2全填进去！ */
    cout << s3;
    return 0;
}