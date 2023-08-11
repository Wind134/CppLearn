/*
限定误差范围是10^-8
*/
#include <iostream>
#include <cmath>
using namespace std;
#define eps 1e-8

int cmp(double formula1, double formula2)
{
    if (formula1 - formula2 > eps) 
        return 1;
    else if (formula1 - formula2 < -eps)
        return 2;
    else return 0;  // 在区间范围
}

int main ()
{
    int a, b, c, d;
    double result1, result2;
    cin >> a >> b >> c >> d;
    result1 = a * asin(sqrt(b) / 2);
    result2 = c * asin(sqrt(d) / 2);
    cout << cmp(result1, result2) << endl;
    return 0;
}