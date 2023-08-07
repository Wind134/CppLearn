/*
题目：
- n位格雷码序列是一个由2^n个整数组成的序列，其中：
- 每个整数都在范围[0, 2^n - 1]内(含0和2^n - 1)
- 第一个整数是0
- 一个整数(十进制数)在序列中出现不超过一次
- 每对相邻整数的二进制表示恰好一位不同，且
- 第一个和最后一个整数的二进制表示恰好一位不同(相当于又给旋回去了)

思路：利用对称性做这道题，以n = 3 为例，必须得写一下思路，不然估计后面看不懂
* 0 0 0
* 0 0 1     到这里我们已经锁定了一对，由于需要保证每对相邻整数的二进制表示恰好一位不同，我们直接利用对称性，然后前一位变成1；
* 0 1 1     将第三行与第二行对称处理，将第2位的0变成1；
* 0 1 0     将第四行与第一行对称处理，将第2位的0变成1；这样就完成了2^2行
* 1 1 0     继续对称处理，第五行与第四行对称处理，将第3位的1->0，下面依次同样处理
* 1 1 1
* 1 0 1
* 1 0 0     显然，这就是规律
*/
#include "../headfile/io_for_leetcode.h"
#include <cmath>
using namespace std;

vector<int> grayCode(int n)
{
    if(n == 1)  return {0, 1};

    int size = pow(2, n);
    vector<int> result(size, 0);    // result数组中元素的个数，每个都先初始化为0

    int begin_index = 1;            // 开始的行索引

    for (int i = 1; i <= n; ++i)
    {
        int total_array_num = 2 * begin_index;   // 每一行要处理的元素数目，比如说第一行，需要处理的元素数目就是2

        for(int j = 0; j < begin_index; ++j)
        {
            int next_index = begin_index + j;   // 从起始索引开始，处理这一行的每一个元素
            result[next_index] = pow(2, i - 1) + result[total_array_num - 1 - next_index];
        }
        begin_index *= 2;    // 这个代表的是每当新增新的一行，起始索引就要发生变化
    }

    return result;
    
}

int main()
{
    int input;

    cin >> input;

    auto output_res = grayCode(input);

    output output89;

    output89.output_array(output_res);

    return 0;
}