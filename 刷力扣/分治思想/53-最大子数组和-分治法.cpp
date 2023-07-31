/*
53题的另一种解法：
- 采用分治法重新思考这道题，对于一个长数组而言，其连续子序列的最大数组和，来源于以下三部分：
- [left, mid]区间的最大和；
- [mid + 1, right]区间的最大和；
- 所有包含nums[mid], nums[mid + 1]的子区间的数组最大和；
- 当然还有一个细节是，题目中要求子数组连续

基于此，可用递归；
*/
#include "../headfile/io_for_leetcode.h"
#include <algorithm>
using namespace std;

int getMax(int nums1, int nums2, int nums3) // 取三个数中最大值的函数，自行定义
{
    return max(max(nums1, nums2), nums3);
}


// 求所有包含nums[mid]以及nums[mid + 1]的子区间的数组最大和
// 这里可以分两部分，即求[left, mid]以及[mid + 1, right]两个区间的最大和
// 分别向左向右扩散，这里要明白的是，一定要有left这个位置，因此问题就简单了
int maxCrossingSum(const vector<int>& nums, int left, int mid, int right)
{
    int sum = 0;
    int leftSum = -10001, rightSum = -10001;    // 先定义一个超出范围的最小值

    // [left, mid]区间
    for(int i = mid; i >= left; i--)
    {
        sum += nums[i];
        if(sum > leftSum)   leftSum = sum;
    }

    sum = 0;

    // [mid + 1, right]区间
    for(int i = mid + 1; i <= right; i++)
    {
        sum += nums[i];
        if(sum > rightSum)   rightSum = sum;
    }

    return leftSum + rightSum;
}


int maxSubArrayPart(const vector<int>& nums, int left, int right)
{
    if(left == right)   return nums[left];  // 边界

    int mid = (left + right) / 2;

    return getMax(maxSubArrayPart(nums, left, mid), maxSubArrayPart(nums, mid + 1, right),
    maxCrossingSum(nums, left, mid, right));
}



int maxSubArray(const vector<int>& nums)
{
    if (nums.size() == 0)   return 0;

    return maxSubArrayPart(nums, 0, nums.size() - 1);
}

int main()
{
    input input53;
    
    auto vec = input53.input_vector();

    cout << maxSubArray(vec) << endl;
}

