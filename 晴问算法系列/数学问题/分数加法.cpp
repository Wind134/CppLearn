#include <iostream>
#include <algorithm>
using namespace std;

struct Data
{
    int up, down;
};

int gcd(const int& a, const int& b) // 求最大公约数
{
    if (a % b == 0) return b;
    else    return gcd(b, a % b);    
}

Data afterProcess(Data& d)
{
    int gcdNum = gcd(abs(d.up), abs(d.down));
    d.up /= gcdNum;
    d.down /= gcdNum;
    if (d.down < 0)
    {
        d.up = -d.up;
        d.down = -d.down;
    }      
    return d;
}



int main()
{
    Data dataValue1;
    Data dataValue2;    // 题目条件隐含，分母一定为正
    Data sumValue;
    cin >> dataValue1.up >> dataValue1.down >> dataValue2.up >> dataValue2.down;
    if (dataValue1.down == dataValue2.down)
    {
        sumValue.up = dataValue1.up + dataValue2.up;
        sumValue.down = dataValue1.down;
    }
    else
    {
        sumValue.down = dataValue1.down * dataValue2.down / gcd(dataValue1.down, dataValue2.down);
        sumValue.up = dataValue1.up * dataValue2.down / gcd(dataValue1.down, dataValue2.down)
        + dataValue2.up * dataValue1.down / gcd(dataValue1.down, dataValue2.down);
    }
    Data result = afterProcess(sumValue);
    if (result.down != 1)   cout << result.up << " " << result.down << endl;
    else cout << result.up << endl;
}
