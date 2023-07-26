/* 
题目：
- 这是一个数学问题，题目要求在不调库的前提下解决问题

思路：
- 关键点在于越界处理，什么情况下会存在越界，在被除数为int范围下界的时候，除以-1，会越界
- 其余情况，无论如何都不会越界，所以单独处理即可
- 把[-2^31, 2^31-1]这个区间的除法分为-2^31 / -1以及[-2^31, 2^31-1]除以任何数的情况
- 用减法的思想代替除法是很正确的，但是时间复杂度存在很大的调优空间
- 由于int型的合法区间并不对称，因此我们选择范围更大的那一方进行处理，这部分都处理好了，那范围更小的那部分自然就没什么问题了
- [-2^31, 2^31-1]这个区间，我们把正数进行投射成负数部分即可，
- 针对负数区间我们采用优化算法：不一个一个减，而是每次减去被除数的更多倍数
    -- 以-30 / 3为例:
    -- 第一次，被除数+3, res = -1, 此时被除数为-27，我们这个时候加6，即加前一次的两倍,res = res + -1 * 2 = -3(加了两倍嘛)，此时被除数为-21
    -- 我们再试着加前一次的两倍12(只要相加之后被除数小于0，就一直这么处理), res = res + -1 * 4 = -7，此时被除数为-9;
    -- 但这个时候发现不能加两倍了，因为加完之后会大于0，但是剩下的-9依然比初始的除数绝对值要大，说明还可以处理
    -- 那我们试着退一步，不加12的两倍了，加12的1 / 2(一定可以满足条件，数学上可以证明), res = res + -1 * 2 = -9，此时被除数为-3
    -- 然后继续同理，加6的1 / 2,res = -10, 即为结果，此时被除数绝对值完全小于除数绝对值，得到最终结果 
- 从而得到时间的优化，这样就是一个很不错的算法
 */
#include <iostream>
#include <climits>
using namespace std;

int divide(int dividend, int divisor)
{
    int result = 0; // 初始值为0

    if (dividend == INT_MIN) {
        if (divisor == -1)  return INT_MAX;
        else if (divisor == 1)  return INT_MIN;
        else if (divisor > 0)   return divide(INT_MIN + divisor, divisor) - 1;
        else return divide(INT_MIN - divisor, divisor) + 1;
    }
    

    else    // 其他的所有情况
    {
        if (divisor == INT_MIN)  return 0;
        int absDivisor = abs(divisor);      // 保持除数为正数即可
        int exp = 0;    // 初始指数为0
        int new_diviend = (dividend < 0) ? dividend : -dividend;
        
        while (new_diviend + abs(divisor) <= 0)  // 只要被除数大于起初的除数，就不断循环
        {
            if (new_diviend + absDivisor <= 0)  // 先加，再判断
            {
                new_diviend += absDivisor;
                absDivisor <<= 1;   // 被除数(绝对值)扩大2倍，即左移一位
                result -= (1 << exp);
                exp++;
            }
            else
            {
                absDivisor >>= 1;   // 除数缩小为1 / 2
                exp--;
            }
        }
    }

    return (dividend > 0 && divisor < 0 || dividend < 0 && divisor > 0) ? result : -result;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << divide(a, b) << endl;
}