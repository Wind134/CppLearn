/*
题目：
- 给你一个整数数组nums，请你找出一个具有最大和的连续子数组(子数组最少包含一个元素)，返回其最大和；
- 子数组是数组中的一个连续部分；
 
思路：动态规划是永远的出路，其实动态规划本质上是找递推式，我们找到一个可以用递推式递推下一个状态的结果的状态；
- 我们可以假设这么一种状态：索引为index，以nums[index]为结尾的数组，他的最大值是多少呢？我们假设这个值为dp_array[index]；
- 显然，如果dp_array[index - 1]的值大于0，即所有以index - 1处的元素为结尾的数组的最大值是果dp_array[index - 1]；
- 如果这个值大于0，显然针对nums[index]而言，以这个数为结尾的子数组的最大和应该加上前一个dp_array[index - 1]；
- 否则就只能是nums[index]本身了，因为前面如果为负，加上更小，那就没有加上去的必要了；
    -- value_end_max[index] = value_end_max[index - 1] + nums[index]     // value_end_max[index - 1] > 0
                            = nums[index]                                // value_end_max[index - 1] <= 0
* 其中，value_end_max[0] = nums[0]

*/
#include "../headfile/io_for_leetcode.h"
#include <algorithm>
using namespace std;


int maxSubArray(const vector<int>& nums)
{
    vector<int> storage(nums.size(), 0);    // 存储以数组中对应索引为结尾的数组的最大值
    storage[0] = nums[0];
    for(int i = 1; i < nums.size(); i++)
    {
        if(storage[i - 1] > 0)  // 如果前一个状态
            storage[i] = storage[i - 1] + nums[i];  // 不要被num[i]的正负所迷惑
        else    storage[i] = nums[i];
    }

    int result = storage[0];
    for(int i = 1; i < nums.size(); i++)    result = max(result, storage[i]);
    return result;
}

int main()
{
    input input53;
    
    auto vec = input53.input_vector();

    cout << maxSubArray(vec) << endl;
}

