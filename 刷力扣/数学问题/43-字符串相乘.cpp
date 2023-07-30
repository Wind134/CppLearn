/* 
题目：给定两个以字符串形式表示的非负整数num1和num2，返回num1和num2的乘积，它们的乘积也表示为字符串形式。

注意：不能使用任何内置的BigInteger库或直接将输入转换为整数。


思路：直接算是不可能的，200位一定会溢出(更正：可以算，每次结果以字符串的形式处理即可，这样时间复杂度会高一点)
- 这是一个数学问题，具体来说就是：
    -- 两位分别为m位和n位的数相乘，相乘后的结果要么是(m + n)位，要么是(m + n - 1)位
    -- num1​[i]×num2​[j]的结果位于resultArr[i+j+1],如果resultArr[i+j+1] ≥ 10，则将进位部分加到resultArr[i+j]。
- 上面这部分有关乘法的规则是做这道题的关键；    
- 因此我们维护一个(m + n)位的数组用于存储结果，最后将数组转为字符串即可；
* 数组中的每一位按照进位法则来处理；
*/
#include "../headfile/io_for_leetcode.h"
using namespace std;

string multiply(string num1, string num2) 
{
    vector<int> resultArray(num1.size() + num2.size()); // 预先定义一个结果数组

    if (num1 == "0" || num2 == "0") return "0";         // 特殊情况结果

    for (int j = num2.size() - 1; j >= 0; j--) {         // 乘数随着指针的移动而移动
        for(int i = num1.size() - 1; i >= 0; i--) {
            if (resultArray[i + j + 1] >= 10) { // i + j + 1是num1的第i位与num2的第j位相乘后结果的位置(这是数学原因)
                resultArray[i + j]++;           // 前1位因此需要进位(我们放在每一轮新的循环的开始处处理之前因为自增而可能导致的前一位进位情况)
                resultArray[i + j + 1] -= 10;   // 更新该位的值
            }

            int num1_val = num1[i] - '0';    
            int num2_val = num2[j] - '0';

            if (num1_val * num2_val >= 10) {
                int incr_step = num1_val * num2_val / 10;   // 这是下一位要自增的步数(结果不仅仅只可能大于10)
                int real_add = num1_val * num2_val % 10;    // 真实相加值
                resultArray[i + j + 1]  +=  real_add;       // 相加

                if (resultArray[i + j + 1] >= 10) {         // 相加后可能又大于等于10
                    resultArray[i + j] += (incr_step + 1);  // (i + j)这个位置，会等到后续轮到他的时候又被处理
                    resultArray[i + j + 1] -= 10;
                }
                else    resultArray[i + j] += incr_step;
            }
            else {
                resultArray[i + j + 1]  += num1_val * num2_val;
                if (resultArray[i + j + 1] >= 10) {  // 0~9之间的两个数相加的结果只可能在0~18之间
                    resultArray[i + j] += 1;
                    resultArray[i + j + 1] -= 10;
                }
            }
        }
    }

    int begin = 0;
    while (resultArray[begin] == 0) begin++;
    
    stringstream ss;

    for (int i = begin; i < resultArray.size(); i++)
    {
        ss << resultArray[i];
    }

    string result = ss.str();
    
    return result;
}
int main()
{
    string input1, input2;
    cin >> input1 >> input2;
    cout << multiply(input1, input2) << endl;
}
