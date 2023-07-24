/*
题目：
给定两个大小分别为m和n的正序(从小到大)数组nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。

要求算法的时间复杂度为O(log(m+n))。


思路：
- 通过二分去定位处于中间位置的那个元素，由于是二分，很好的控制了时间复杂度，这应该是最佳做法
*/

#include "../headfile/io_for_leetcode.h"
#include <algorithm>
using namespace std;


int getKthElement(const vector<int>& nums1, const vector<int>&nums2, int k)  // 获取两个数组中的第k个元素
{
    int m = nums1.size(), n = nums2.size();
    int nums1Index = 0, nums2Index = 0;
    
    while (true)
    {
        // 处理边界情况
        if (nums1Index == m)    return nums2[nums2Index + k - 1];
        if (nums2Index == n)    return nums1[nums1Index + k - 1];
        if (k == 1)     return min(nums1[nums1Index], nums2[nums2Index]);

        // 处理正常情况
        int newIndex1 = min(nums1Index + k / 2 - 1, m - 1);             // 不断进位
        int newIndex2 = min(nums2Index + k / 2 - 1, n - 1);
        int value1 = nums1[newIndex1], value2 = nums2[newIndex2];       // 做值的比较
        if (value1 <= value2)
        {
            k -= newIndex1 - nums1Index + 1;
            nums1Index = newIndex1 + 1;
        }
        else
        {
            k -= newIndex2 - nums2Index + 1;
            nums2Index = newIndex2 + 1;
        }
    }
    

}

double findMedianSortedArrays(const vector<int>& nums1, const vector<int>& nums2)
{
    int totalLength = nums1.size() + nums2.size();
    if (totalLength % 2 == 1) 
    {
        return getKthElement(nums1, nums2, (totalLength + 1) / 2);
    }
    else 
    {
        return (getKthElement(nums1, nums2, totalLength / 2) + getKthElement(nums1, nums2, totalLength / 2 + 1)) / 2.0;
    }
}

int main()
{
    input input4_1, input4_2;
    auto vec1 = input4_1.input_vector();
    auto vec2 = input4_2.input_vector();
    double value = findMedianSortedArrays(vec1, vec2);
    cout << "中位数的值为：" << value << endl;
    return 0;
}
