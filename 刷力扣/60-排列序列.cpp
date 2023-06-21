/*
* 给出集合[1,2,3,...,n]，其所有元素共有n!种排列。
* 按大小顺序列出所有排列情况，并一一标记。

* 给定n和k，返回第k个排列。

* 这道题主要还是通过找规律的方式解决的
*/

#include <iostream>
#include <vector>
#include <string>
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
    if(k == 1 || n == 1) return;
    if(k == fact(n))
    {
        for(int left = index, right = str.size() - 1; left < right; left++, right--)
        {
            swap(str[left], str[right]);
        }
        return;
    }

    // 进行递归处理
    int temp_value = fact(n - 1);
    int times = k / temp_value;
    int remain = k % temp_value;
    if (remain == 0)
    {
        // 能整除是一种特殊情况，需要轮换处理
        for (int i = 0; i < times - 1; i++)
        {
            swap(str[index], str[index + i + 1]);
        }

        // 从下一个索引开始直接翻转
        for(int left = index + 1, right = str.size() - 1; left < right; left++, right--)
        {
            swap(str[left], str[right]);
        }
        return;
    }

    // 如果不能整除
    else
    {
        // 先进行轮换
        for (int i = 0; i < times; i++)
        {
            swap(str[index], str[index + i + 1]);
        }
        // k值更新为余数值remain，更新n与索引index
        process(str, n - 1, remain, index + 1);
    }
}

string getPermutation(int n, int k)
{
    // 通过给定的n建立一个初始string
    string init_string;
    char end = static_cast<char>('0' + n);
    for(auto it = '1'; it <= end; it++) init_string.push_back(it);

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