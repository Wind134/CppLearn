/**
 * 已知一个长度为n的数组，预先按照升序排列，经由1到n次旋转后，得到输入数组。例如，原数组Wnums = [0,1,2,4,5,6,7]在变化后可能得到：
 * 若旋转4次，则可以得到[4,5,6,7,0,1,2]
 * 若旋转7次，则可以得到[0,1,2,4,5,6,7]
 * 
 * 注意:
 * 数组[a[0], a[1], a[2], ..., a[n-1]]旋转一次的结果为数组[a[n-1], a[0], a[1], a[2], ..., a[n-2]]。
 * 给你一个元素值互不相同的数组nums ，它原来是一个升序排列的数组，并按上述情形进行了多次旋转。
 * 请你找出并返回数组中的最小元素。
 * 你必须设计一个时间复杂度为O(log n)的算法解决此问题。
 * 
 * 思路：二分找逆序位置即可
 */
#include "../headfile/io_for_leetcode.h"
using namespace std;

int findMin(vector<int>& nums) {
    if (nums.size() == 1)   return nums[0];

    int left = 0, right = nums.size() - 1;

    while (left < right) {
        int mid = (left + right) >> 1;
        
        if (nums[mid] < nums[0]) { // mid属逆序区间，目标值不可能在右边
            if (nums[mid - 1] > nums[mid])  return nums[mid];
            right = mid - 1;
        }
        else {
            if (nums[mid + 1] < nums[mid])  return nums[mid + 1];
            left = mid + 1;
        }
    }

    return nums[0];     // 没有逆序则返回第一个
}

int main() {
    input input153;
    auto vec = input153.input_vector();

    cout << findMin(vec) << endl;

    return 0;
}