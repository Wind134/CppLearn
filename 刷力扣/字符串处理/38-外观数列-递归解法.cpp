/*
题目：
- 给定一个正整数n，输出外观数列的第n项。
- 「外观数列」是一个整数序列，从数字1开始，序列中的每一项都是对前一项的描述。
- 你可以将其视作是由递归公式定义的数字字符串序列：

- 理解这个外观数列就花了很久...
- 1.     1
- 2.     11
- 3.     21
- 4.     1211
- 5.     111221
- 第一项是数字1 
- 描述前一项，这个数是1 即“一个1”，记作"11"
- 描述前一项，这个数是11 即 “二个1” ，记作"21"
- 描述前一项，这个数是21 即 “一个2 + 一个1”，记作"1211"
- 描述前一项，这个数是1211 即 “一个1 + 一个2 + 二个1” ，记作"111221"
- 其实本质上就是一 -> 1，二 -> 2，文字版数字转数字

思路：基本锁定要递归了
- 基本的递推式：对于第i项要描述的字符串str，str = countAndSay(n - 1)是毫无疑问的；
- 而我们需要观察的是，这个str的规律会是什么，显然它的位数是"文字版"数字和"数字版"数字之和；
- 那么我们就需要针对该字符串去做遍历，去判断规律；
*/
#include <iostream>
#include <string>
using namespace std;


string countAndSay(int n)
{ 
    string result = ""; // 初始为空
    int count = 1;
    if (n == 1) return "1";
    else 
    {
        string str = countAndSay(n - 1);
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == str[i + 1])   // 如果相等，我们就判断相等的个数有几个，比如11，我们描述为两个1
            {
                count++;
            }
            else    // 如果遇到不等的了，那我们就可以将信息写入结果了
            {         // 统计到的个数转为字符串 //统计的那个字符串
                result +=  to_string(count) + str[i];
                count = 1;
            }
        }
        return result;
    }
}

int main()
{
    int n;
    cin >> n;

    cout << countAndSay(n) << endl;
}