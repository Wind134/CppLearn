/* 
* 一条包含字母A-Z的消息通过以下映射进行了编码：

'A' -> "1"
'B' -> "2"
...
'Z' -> "26"

要解码已编码的消息，所有数字必须基于上述映射的方法，反向映射回字母（可能有多种方法）。例如，"11106" 可以映射为：

"AAJF"，将消息分组为(1 1 10 6)
"KJF"，将消息分组为(11 10 6)
注意，消息不能分组为(1 11 06)，因为"06"不能映射为"F"，这是由于"6"和"06"在映射中并不等价。

给你一个只含数字的非空字符串s，请计算并返回解码方法的总数。

题目数据保证答案肯定是一个32位的整数。

思路：每次只能选取两位或者一位，选1位的时候要保证数字在"1-9"之间；
选两位的时候要保证数字在"10-26"之间

思路：回溯(寄！超时！)
*/
#include <iostream>
#include <string>
using namespace std;

int method_nums = 0;

void backtrace(const string& s, int index)
{
    if(index == s.size())
    {
        method_nums++;
        return;
    }

    // 选1位的场景
    if(s[index] - '0' > 0 && s[index] - '0' < 10)   backtrace(s, index + 1);

    // 选2位的场景
    if((s[index] - '0') * 10 + (s[index + 1] - '0') > 9 && (s[index] - '0') * 10 + (s[index + 1] - '0') < 27)
        backtrace(s, index + 2);
}

int numDecodings(string s)
{
    backtrace(s, 0);
    return method_nums;
}

int main()
{
    string input;
    cin >> input;

    cout << numDecodings(input) << endl;

    return 0;
}
