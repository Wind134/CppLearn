/*  
* 给定两个以字符串形式表示的非负整数num1和num2，返回num1和num2的乘积，它们的乘积也表示为字符串形式。
* 
* 注意：不能使用任何内置的BigInteger库或直接将输入转换为整数。
* 思路：直接算是不可能的，200位一定会溢出(更正：可以算，以字符串的形式处理即可，这样时间复杂度会高一点)
* 这是一个数学问题，具体来说就是：两位分别为m位和n位的数相乘，相乘后的结果要么是(m + n)位，要么是(m + n - 1)位
* 此外num1​[i]×num2​[j]的结果位于resultArr[i+j+1],如果ansArr[i+j+1]≥10，则将进位部分加到ansArr[i+j]。
* 因此我们维护一个(m + n)位的数组用于存储结果，最后将数组转为字符串即可；
* 数组中的每一位按照进位法则来处理；
*/

#include <string>
#include <iostream>
#include <vector>
using namespace std;

string multiply(string num1, string num2) 
{
    vector<int> resultArray(num1.size() + num2.size());

    if (num1 == "0" || num2 == "0") return "0";

    for (int j = num2.size() - 1; j >= 0; j--)
    {
        for(int i = num1.size() - 1; i >= 0; i--)
        {
            if (resultArray[i + j + 1] >= 10)   // 这一步保证了每次循环到同样的索引位置，都会判断这个位置是否超过10
                {
                    resultArray[i + j]++;
                    resultArray[i + j + 1] -= 10;
                }
            if ((num1[i] - '0') * (num2[j] - '0') >= 10)
            {
                int incr_step = (num1[i] - '0') * (num2[j] - '0') / 10;
                int real_add = (num1[i] - '0') * (num2[j] - '0') % 10;
                resultArray[i + j + 1]  +=  real_add;   // 进位处理之后再处理新乘的结果

                if (resultArray[i + j + 1] >= 10)
                {
                    resultArray[i + j] += (incr_step + 1);
                    resultArray[i + j + 1] -= 10;
                }
                else    resultArray[i + j] += incr_step;
                
            }
            else
            {
                resultArray[i + j + 1]  += (num1[i] - '0') * (num2[j] - '0');
                if (resultArray[i + j + 1] >= 10)
                {
                    resultArray[i + j] += 1;
                    resultArray[i + j + 1] -= 10;
                }
            }   
        }
    }

    int begin = 0;
    while (resultArray[begin] == 0) begin++;
    
    string result;
    for (int i = begin; i < resultArray.size(); i++)
    {
        result.push_back(resultArray[i]);
    }

    for (auto& elem : result)   elem += '0';   
    
    return result;
}
int main()
{
    string input1, input2;
    cin >> input1 >> input2;
    cout << multiply(input1, input2) << endl;
}
