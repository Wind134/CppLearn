/*  
* 给一个整数数组nums，返回数组answer，其中answer[i]等于nums中除nums[i]之外其余各元素的乘积。
* 题目数据保证数组nums之中任意元素的全部前缀元素和后缀的乘积都在32位整数范围内。
* 请不要使用除法，且在O(n)时间复杂度内完成此题。
* 思路：动态规划，维护两个数组，l_elem与r_elem，就是说l_elem[i]是索引i左边的数组元素乘积，r_elem是索引i右边的数组元素乘积
* 那么，针对l_elem[i]，他的值是l_elem[i - 1] * num[i - 1]；
* 针对r_elem[i]，他的值是r_elem[i + 1] * num[i + 1];
* 显然，我们找到了动态规划的状态转移方程，那么最后就是确定边界条件了，也就是l_elem[0] = 1(一定要注意，是1，而不是nums[0])
* 对于r_elem的边界条件而言，就是r_elem[nums.size() - 1] = 1;
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(const vector<int>& nums)
{
    int size = nums.size();
    auto l_mutil_result = vector<int>(size);
    auto r_mutil_result = vector<int>(size);
    l_mutil_result[0] = 1;
    r_mutil_result[size - 1] = 1;
    for (int i = 1; i < size; i++)
    {
        l_mutil_result[i] = l_mutil_result[i - 1] * nums[i - 1];
    }

    for (int i = size - 2; i >= 0; i--)
    {
        r_mutil_result[i] = r_mutil_result[i + 1] * nums[i + 1];
    }

    vector<int> result;

    for (int i = 0; i < size; i++)
    {
        result.push_back(l_mutil_result[i] * r_mutil_result[i]);
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

