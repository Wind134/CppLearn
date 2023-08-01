/*
题目：
- 给出集合[1,2,3,...,n]，其所有元素共有n!种排列。
- 按大小顺序列出所有排列情况，并一一标记。
- 给定n和k，返回第k个排列。

思路：
- 这道题主要还是通过找规律的方式解决的，要求返回第k个排列，此时我们分几种情况讨论；
- 如果是要求返回第一个或者最后一个排列，这只需要比较直观的返回策略，这是最容易考虑到的情况；
- 如果要返回的第k个序列的k值刚好是(n-1)种排列迭代完成的情况，显然这个时候的k值应该是(n - 1)!阶乘的倍数，假设倍数是m；
- 这种情况下，返回的只需要交换上一个序列的前面两个位置；
    -- 第一轮的初始序列：1 2 3 4，第6个序列应该是1 4 3 2，下一个序列应该是2开头
        --- 下一个序列应该是怎么来的呢？交换第一个跟第二个元素的位置2 1 3 4
    -- 下一个序列初始应该是：2 1 3 4，第12个序列应该是2 4 3 1，下一个序列应该是以3开头
        --- 下一个序列应该是怎么来的呢？交换第一个跟第三个元素的位置3 1 2 4，从这里大概可以判断到规律，基于上一次交换后的结果，交换元素位置
    -- 依此类推，到m为止，下一个序列的第一个首先是m，基于上一个序列交换第一个跟第m个索引的位置，
    -- 那就是，相对于基准位置，k的索引是(begin + k - 1)，begin是开始的索引，在这个例子中为0、
    -- 因此我们只需要交换这两个索引的值，然后reverse后续子序列即可
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


// 该函数求阶乘
int fact(int n)
{
    if(n == 0 || n == 1)    return 1;
    else
    {
        int result = n * fact(n - 1);
        return result;
    }
}


void process(string& str, int n, int k, int index)
{
    // 下面两种情况不递归，直接返回
    if(k == 1 || n == 1) return;    // 如果要求返回第一个排列，则str是本身
    if(k == fact(n))                // 如果是返回最后一个排列，则返回交换位置后的结果即可
    {
        reverse(str.begin(), str.end());    // 翻转
        return;
    }

    // 进行递归处理，递归是为了处理index位置上的元素
    int temp_value = fact(n - 1);
    int times = k / temp_value;
    int remain = k % temp_value;
    if (remain == 0)    // 如果可以整除，说明该位置上的元素不需要处理
    {
        // 能整除是一种特殊情况，需要轮换处理
        for (int i = 1; i <= times; i++) swap(str[index], str[index + i - 1]);
        // 从下一个索引开始直接翻转
        reverse(str.begin() + index + 1, str.end());
        return;
    }
    // 如果不能整除
    else
    {
        // 先进行轮换，这里轮换的处理与上面稍有不同
        for (int i = 0; i <= times; i++) swap(str[index], str[index + i]);

        // k值更新为余数值remain，更新n与索引index，递归处理子串
        process(str, n - 1, remain, index + 1);
    }
}

string getPermutation(int n, int k)
{
    // 通过给定的n建立一个初始string
    string init_string;
    char end = static_cast<char>('0' + n);
    for(auto it = '1'; it <= end; it++) init_string.push_back(it);  // 建立初始串

    // 将该string传入process函数
    process(init_string, n, k, 0);
    return init_string;
}

int main()
{
    int input_n, input_k;
    cin >> input_n >> input_k;

    cout << getPermutation(input_n, input_k) << endl;
}