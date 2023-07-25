/*
题目：
- 给一个整数，转化为罗马数字


思路：递归加枚举解决问题，但貌似多了很多重复运算，因此这个方式改进一下
*/
#include <iostream>
#include <string>
using namespace std;


void intToRoman(const int& num, string &result)
{
    int remainder;
    if(num >= 1000)
    {
        for (int i = 0; i < num / 1000; i++)
            result += "M";
        remainder = num % 1000;
        intToRoman(remainder, result);
    }
    else if (num >= 900)
    {
        result += "CM";
        remainder = num % 900;
        intToRoman(remainder, result);
    }
    else if (num >= 500)
    {
        result += "D";
        remainder = num % 500;
        intToRoman(remainder, result);
    }
    else if (num >= 400)
    {
        result += "CD";
        remainder = num % 400;
        intToRoman(remainder, result);
    }
    else if (num >= 100)
    {
        for (int i = 0; i < num / 100; i++)
            result += "C";
        remainder = num % 100;
        intToRoman(remainder, result);
    }
    else if (num >= 90)
    {
        result += "XC";
        remainder = num % 90;
        intToRoman(remainder, result);
    }
    else if (num >= 50)
    {
        result += "L";
        remainder = num % 50;
        intToRoman(remainder, result);
    }
    else if(num >= 40)
    {
        result += "XL";
        remainder = num % 40;
        intToRoman(remainder, result);
    }
    else if(num >= 10)
    {
        for (int i = 0; i < num / 10; i++)
            result += "X";
        remainder = num % 10;
        intToRoman(remainder, result);
    }
    else if (num == 9) result += "IX";
    else if (num >= 5)
    {
        result += "V";
        remainder = num % 5;
        intToRoman(remainder, result);
    }
    else if( num == 4)  result += "IV";
    else
    {
        for (int i = 0; i < num; i++)
            result += "I";
        return;    
    }
}

int main()
{
    int num;
    string result = "";
    cin >> num;
    intToRoman(num, result);
    cout << result << endl;
    return 0;
}