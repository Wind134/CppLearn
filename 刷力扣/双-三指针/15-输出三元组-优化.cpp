/* 
题目：略

思路：采用双指针法(其实本质上是三指针)，时间复杂度降至n^2
*/
#include "../headfile/io_for_leetcode.h"
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) 
{
    vector<vector<int>> result; // 默认初始化
    sort(nums.begin(), nums.end());     // 默认升序

    for (int left = 0; left < nums.size() - 2; left++)      // 移动left
    {
        if (nums[left] + nums[left + 1] + nums[left + 2] > 0)   break;
        int medium = left + 1;
        int right = nums.size() - 1;
        int target = -nums[left];
        while (medium < right) {
            if (nums[medium] + nums[right] == target) {
                result.push_back({nums[left], nums[medium], nums[right]});
                while(nums[right] == nums[right - 1] && right > medium) right--;    // 同时向自己的方面前进
                while(nums[medium] == nums[medium + 1] && medium < right) medium++;
                right--;
                medium++;
            }
            else if (nums[medium] + nums[right] > target)   right--;
            else medium++;
        }
        
        // 下面这个循环主要是为了跳过重复值，而且还得放在最下面：3 + 3 + 4 = 7 | 放在上面部分去执行会跳过这么一个答案
        // 可能还会有些疑惑，比如说3 3 3这么一个答案呢，是不是需要考虑最右边呢？显然不需要，因为这样就锁定答案了.....
        while(left < nums.size() - 1 && nums[left+1] == nums[left])   left++;
    }
    return result;
}

int main()
{
    input input15;
    auto vec = input15.input_vector();

    vector<vector<int>> threeSumarray = threeSum(vec);
    output output15;
    output15.output_matrix(threeSumarray);
    return 0;
}


