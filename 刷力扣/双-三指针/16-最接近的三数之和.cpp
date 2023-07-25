/*
题目：
- 给你一个长度为n的整数数组nums和一个目标值target。
- 请你从nums中选出三个整数，使它们的和与target最接近。
- 返回这三个数的和。
- 假定每组输入只存在恰好一个解。

思路：
*/
#include "../headfile/io_for_leetcode.h"
#include <algorithm>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) 
{
    int left = 0;       // 最左边的变量
    sort(nums.begin(), nums.end()); // 将数组进行排序
    int subValue = INT_MAX;
    int result = nums[0] + nums[1] + nums[nums.size() - 1];
    // int initValue = abs(nums[0] + nums[1] + nums[nums.size() - 1] - target);
    while (left < nums.size() - 2)
    {
        int right = nums.size() - 1;
        int medium = left + 1;
        while (right > medium)
        {
            int sum = nums[left] + nums[medium] + nums[right];
            if (sum - target > 0)
            {
                right --;
                if (sum-target < subValue)
                {
                    subValue = sum-target;
                    result = sum;
                }
            }
            else  if (sum - target == 0)
            {
                return sum;
            }
            else
            {
                medium++;
                if (target - sum < subValue)    // 不断更新更小的差值
                {
                    subValue = target - sum;
                    result = sum;
                }
            }
        }
        left++;
    }
    return result;
}

int main()
{
    input input16;
    auto vec = input16.input_vector();
    cout << "Input the target: ";
    int target; cin >> target;

    int sum = threeSumClosest(vec, target);
    cout << sum << endl;
    return 0;
}



