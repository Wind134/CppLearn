/*
题目：
- 给一个整数，转化为罗马数字；


思路：递归加枚举解决问题，但貌似多了很多重复运算，因此这个方式改进一下；
*/
#include <iostream>
#include <string>
using namespace std;

const pair<int, string> valueSymbols[] = {  // 将特殊的字符与对应数字联系起来
    {1000, "M"},
    {900,  "CM"},
    {500,  "D"},
    {400,  "CD"},
    {100,  "C"},
    {90,   "XC"},
    {50,   "L"},
    {40,   "XL"},
    {10,   "X"},
    {9,    "IX"},
    {5,    "V"},
    {4,    "IV"},
    {1,    "I"},
};


string intToRoman(int num)
{
    string roman;
    for (const auto &[value, symbol] : valueSymbols) {
        while (num >= value) {
            num -= value;
            roman += symbol;
        }
        if (num == 0) {
            break;
        }
    }
    return roman;
}

int main()
{
    int num;
    cin >> num;
    string result = intToRoman(num);
    cout << result << endl;
    return 0;
}