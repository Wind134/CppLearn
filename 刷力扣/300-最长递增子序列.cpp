/* 
* 给你一个整数数组nums，找到其中最长严格递增子序列的长度(没说必须得连续)。

* 子序列是由数组派生而来的序列，删除(或不删除)数组中的元素而不改变其余元素的顺序。
* 例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。

* 思路：思路上有些类似于30题，找以数组中每一个index上元素为结尾(包括index)的数组中最长的递增序列

* 其中length_est[0] = 1;

* 我设计的状态转移方程，假设此时的索引是index，如果nums[index] > nums[i]:
length_est[index] = max(length_est[i]) + 1  (0 <= i <= index - 1)，即i从0~index-1每个样本都要遍历一遍
如果小于呢nums[index] <= nums[i]呢，这种情况(我们优先给length_est[index]一个初始值即可)

那么以该index上元素为结尾的数组中递增序列的最大值取决于：
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lengthOfLIS(const vector<int>& nums) 
{
    int n = (int)nums.size();

    if(n == 0)  return 0;
    vector<int> storage(nums.size(), 0);

    for(int i = 0; i < nums.size(); i++)
    {
        storage[i] = 1;
        for(int j = 0; j < i; j++)
        {
            if(nums[j] < nums[i])
                storage[i] = max(storage[i], storage[j] + 1);
        }
    }

    int result = storage[0];

    for (int i = 1; i < nums.size(); i++)
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
    
    cout << lengthOfLIS(input) << endl;
}