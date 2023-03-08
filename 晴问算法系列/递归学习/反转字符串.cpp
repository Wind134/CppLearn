/* abcde -> edcba */
#include <iostream>
#include <string>
using namespace std;

string s;

string reverseStr(size_t n)    // 对于长为n的字符串
{
    if (n == 1) return s.substr(0, n);      // 长为1的时候返回自身即可
    else
    {
        return s.substr(n - 1, 1) + reverseStr(n - 1); 
    }
}

int main()
{
    cin >> s;
    cout << reverseStr(s.size());
    return 0;
}
