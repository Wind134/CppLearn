/* 用减法的思想代替除法是很正确的，但是时间复杂度存在很大的调优空间
由于int型的合法区间并不对称，因此我们选择范围更小的那一方进行投射即可
[-2^31, 2^31-1]这个区间，我们把正数进行投射即可，最终的下界单独处理即可
因此针对正数区间我们采用优化算法：不一个一个减，而是每次减去被除数的更多倍数
从而得到时间的优化，这样就是一个很不错的算法
 */
#include <iostream>
#include <cmath>
using namespace std;

const int& INT_MIN = -pow(2, 31);
const int& INT_MAX = pow(2, 31) - 1;

int divide(int dividend, int divisor)
{
    int result = 0; // 初始值为0
    // 仅有在dividend遇到下界时才会需要特殊处理
    // if (dividend == MinV && divisor == -1)   return pow(2, 31) - 1;
    if (dividend == INT_MIN)
    {
        if (divisor > 0 )
        {
            return -divide(-(dividend + divisor), divisor) - 1;
        }
        else
        {
            if (divisor == -1) return INT_MAX;
            else return divide(dividend - divisor, divisor) + 1;
        }
    }
    else
    {
        int absDividend = abs(dividend);
        if (divisor == INT_MIN)  return 0;
        int absDivisor = abs(divisor);   
        if (absDividend < absDivisor) return 0;
        int tempresult = 0;
        while (absDividend >= abs(divisor))  // 只要被除数大于起初的除数，就不断循环
        {
            if (absDividend >= absDivisor)
            {
                absDividend -= absDivisor;
                absDivisor <<= 1;   // 被除数扩大2倍，即左移一位
                result += (1 << tempresult);
                tempresult++;
            }
            else
            {
                absDivisor >>= 1;   // 右移一位
                tempresult--;
            }
        }
        return (dividend > 0 && divisor < 0 || dividend < 0 && divisor > 0) ? -result : result;
    }
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << divide(a, b) << endl;
}