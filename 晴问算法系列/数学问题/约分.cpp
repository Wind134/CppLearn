#include <iostream>
#include <algorithm>
using namespace std;

struct Data
{
    int up, down;
};

int gcd(const int& a, const int& b)
{
    if (a % b == 0) return b;
    else    return gcd(b, a % b);    
}

Data afterProcess(Data& d)
{
    int gcdNum = gcd(abs(d.up), abs(d.down));
    d.up /= gcdNum;
    d.down /= gcdNum;
    if (d.up * d.down < 0 && d.down < 0)
    {
        d.up = -d.up;
        d.down = -d.down;
    }      
    return d;
}

int main()
{
    Data dataValue;
    cin >> dataValue.up >> dataValue.down;
    Data result = afterProcess(dataValue);
    if (result.down != 1)   cout << result.up << " " << result.down << endl;
    else cout << result.up << endl;
}
