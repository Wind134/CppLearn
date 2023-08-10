/*
题目：
- 给一个整数数组nums，返回数组answer，其中answer[i]等于nums中除nums[i]之外其余各元素的乘积。
- 题目数据保证数组nums之中任意元素的全部前缀元素和后缀的乘积都在32位整数范围内。
- 请不要使用除法，且在O(n)时间复杂度内完成此题。


思路：
- 我们建立一个数组result，这个数组就是我们要的答案，初始值全为1
- 对nums中的元素进行迭代，每次迭代，我们同时更新result数组中两个值，这两个值
- 分别由两个指针指向，其中左指针不断右移，右指针不断左移，左指针指向的那个
- 值乘前缀，右指针指向的那个值乘后缀；
- 其实就是两个动态规划数组的优化版；
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(const vector<int>& nums)
{
    int size = nums.size();
    auto result = vector<int>(size, 1); // 数组初始值全分配为1
    int prefix = 1, suffix = 1;         // 前缀后缀都初始化为1

    for (int i = 0; i < size; i++)
    {
        result[i] *= prefix;            // 第一次遍历之后的所有值都已经算过左边乘积了
        result[size - i - 1] *= suffix; // 第二次便利之后的所有值将会再算一遍右边乘积
        prefix *= nums[i];              // 更新前缀
        suffix *= nums[size - i - 1];   // 更新后缀
    }    
    return result;
}

int main()
{
    vector<int> input;

    int data;

    while (cin >> data)
    {
        input.push_back(data);
        if (cin.get() == '\n')
        {
            break;
        }
    }
    
    auto result = productExceptSelf(input);

    bool first = true;   // 去除不必要的空格
    for (const int& elem : result)
    {
        if (first)  { cout << elem;  first = false; }
        else cout << " " << elem;
    }
    return 0;
}

