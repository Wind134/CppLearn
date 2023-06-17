/*
* 给你一个整数数组nums，请你找出一个具有最大和的连续子数组(子数组最少包含一个元素)，返回其最大和。
* 子数组是数组中的一个连续部分。

* 思路：采用双指针策略(经过长达俩小时的实践发现做不出来)
* 动态规划是永远的出路，其实动态规划本质上是找递推式，我们找到一个可以用递推式递推下一个状态的结果的状态；
* 针对数组中的每个数[nums[0],nums[1],....,nums[size - 1]]，我们找这么一个值，假设此时索引为index
* 那么以nums[index]为结尾的数组，他的最大值是多少呢？他等于nums[index - 1] + nums[index](nums[index] > 0)
* 此时我们知道，我们要找的状态是，以数组中某个数值结尾的数组的和的最大值，它的递推方程：
* value_end_max[index] = value_end_max[index - 1] + nums[index]     // value_end_max[index - 1] > 0
                       = value_end_max[index - 1]                   // value_end_max[index - 1] <= 0
* 其中，value_end_max[0] = nums[index]

* 上述递推式需要明白的一点是：不要被nums[index]的正负所迷惑，因为value_end_max[index]的意义是：
* 以index处的nums[index]结尾的数组的和的最大值，那就是说这个数组一定得包括nums[index]，nums[index]在这个数组中
* 一定得存在，那么在这种情形下，如果value_end_max[index - 1]为正，代表索引index - 1处的那个结尾的数组的和的最大值为某个值
* 那么索引index处的那个相应的最大值呢：value_end_max[index - 1] + nums[index]，不论你的nums[index]为正为负，value_end_max[index - 1]
* 是他的子问题，而如果value_end_max[index - 1] < 0呢，那我就不必加上value_end_max[index - 1]，我加一个负值岂不是更小
* 而之前的情况是，你没有不加的余地！
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int maxSubArray(const vector<int>& nums)
{
    vector<int> storage(nums.size(), 0);    // 存储以数组中对应索引为结尾的数组的最大值
    storage[0] = nums[0];
    for(int i = 1; i < nums.size(); i++)
    {
        if(storage[i - 1] > 0)  // 如果前一个状态
        {
            storage[i] = storage[i - 1] + nums[i];  // 不要被num[i]的正负所迷惑
        }
        else    storage[i] = nums[i];
    }

    int result = storage[0];
    for(int i = 1; i < nums.size(); i++)
    {
        result = max(result, storage[i]);
    }
    return result;
}

int main()
{
    vector<int> input;
    int input_data;
    while (cin >> input_data)
    {
        input.push_back(input_data);
        if (cin.get() == '\n')
        {
            break;
        }
    }
    
    cout << maxSubArray(input) << endl;
}

