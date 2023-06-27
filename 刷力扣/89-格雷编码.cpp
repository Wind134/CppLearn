/*
* n位格雷码序列是一个由2^n个整数组成的序列，其中：
- 每个整数都在范围 [0, 2^n - 1] 内（含 0 和 2n - 1）
- 第一个整数是 0
- 一个整数在序列中出现 不超过一次
- 每对相邻整数的二进制表示恰好一位不同，且
- 第一个和最后一个整数的二进制表示恰好一位不同

* 思路：利用对称性做这道题，以n = 3 为例，必须得写一下思路，不然估计后面看不懂

* 0 0 0
* 0 0 1     到这里我们已经锁定了一对，由于需要保证每对相邻整数的二进制表示恰好一位不同，我们直接利用对称性，然后前一位变成1
* 0 1 1
* 0 1 0     显然，这两行的最后一位与上面两行的最后一位对称，然后前1位由0->1
* 1 1 0
* 1 1 1
* 1 0 1
* 1 0 0     显然，这四行与上面四行基本是对称的关系，然后前1位变成1
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> grayCode(int n)
{
    if(n == 1)  return {0, 1};

    int size = pow(2, n);
    vector<int> result(size, 0);

    // 这两个是特殊处理的，为了保证下面的for循环一致性，直接就先将这两个索引的值固定
    result[0] = 0;
    result[1] = 1;

    int begin_index = 1;

    for (int i = 1; i < n; i++)
    {
        begin_index *= 2;    // 这个代表的是每当i增1，起始索引就要发生变化，本来用的是pow函数，改用乘法，可以降时间复杂度(其实也没怎么降)
        int temp_array_num = 2 * begin_index;

        int top_bound = pow(2, i);      // 先定义上界，后面有用
        for(int j = 0; j < top_bound; j++)
        {
            int next_index = begin_index + j;
            result[next_index] = top_bound + result[temp_array_num - 1 - next_index];
        }
    }

    return result;
    
}

int main()
{
    int input;

    cin >> input;

    auto output = grayCode(input);

    for(auto elem : output)
    {
        cout << elem << " ";
    }

    cout << endl;

    return 0;
}