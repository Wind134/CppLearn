/*
题目：
- 给你一个按照非递减顺序排列的整数数组nums，和一个目标值target。
- 请你找出给定目标值在数组中的开始位置和结束位置。
- 如果数组中不存在目标值target，返回[-1, -1]。
- 要求必须设计并实现时间复杂度为O(log n)的算法解决此问题。


思路：这是一个高阶二分，更具体来说：
- 在排序数组中查找元素的第一个和最后一个位置；
- 要求时间复杂度为logn，基本思路是二分是没什么问题的
- 左边的尽量往左扩散，直到遇到不是我们要找的那个数或者到达开头
- 右边的尽量往右扩散，直到遇到不是我们要找的那个数或者到达末尾
- 起初版本的算法过于繁杂，先附于后，尝试一种新的算法：
- 常规的二分就是为了寻找某个值，但我们这道题的二分是找两个东西：
- (nums[leftIndex-1] != target && nums[leftIndex] == target)
- (nums[rightIndex+1] != target && nums[rightIndex] == target)

- 其实用递归更好处理这部分
*/
#include "../headfile/io_for_leetcode.h"
using namespace std;

vector<int> searchRange(const vector<int>& nums, int target)
{
    if(nums.size() == 0)    return {-1, -1};
    if(nums.size() == 1) {
        if (nums[0] == target)  return {0, 0};
        else return {-1, -1};
    }

    int leftIndex = -1, rightIndex = -1;    // 初始值都取-1

    int len = nums.size();

    int left = 0, right = len - 1;

    while (left <= right) { // 好像只能分两步走，没法同时找左右边界，先找左边界
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            if (mid == 0) {
                leftIndex = mid;
                break;  // 防超时
            }
            else {
                if (nums[mid - 1] != target) {
                    leftIndex = mid;
                    break;
                }
                else right = mid - 1;
            }
        } else if (nums[mid] > target) right = mid - 1;
        else left = mid + 1;
    }

    left = 0; right = len - 1;

    while (left <= right) { // 好像只能分两步走，没法同时找左右边界，找右边界
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            if (mid == len - 1) {   // 防超时
                rightIndex = mid;
                break;
            }
            else {
                if (nums[mid + 1] != target) {
                    rightIndex = mid;
                    break;
                }
                else left = mid + 1;
            }
        } else if (nums[mid] > target) right = mid - 1;
        else left = mid + 1;
    }

    return {leftIndex, rightIndex};
}
int main()
{
    input input34;

    auto array = input34.input_vector();

    cout << "Input the target: ";
    int target;
    cin >> target;

    vector<int> result = searchRange(array, target);

    cout << result[0] << " " << result[1] << endl;

    return 0;
}

/* 
if (*nums.begin() == target && *(nums.end() - 1) != target)    // 如果第一个值等于0，则仅仅找最右
    {
        leftIndex = 0;
        int i = 0, j = nums.size() - 1; // 循环用
        while(i <= j)
        {
            int mid = (i + j) / 2;
            if (nums[mid] > target) // 目标只能在左范围内
            {
                j = mid - 1;
                if (nums[j] == target)  return {leftIndex, j};
            }
            else if (nums[mid] == target)
            {
                if (nums[mid + 1] > target) return {leftIndex, mid};
                else i = mid + 1;
            }
        }     
    }

    else if (*nums.begin() != target && *(nums.end() - 1) == target)    // 如果第一个值等于0，则仅仅找最右
    {
        rightIndex = nums.size() - 1;
        int i = 0, j = nums.size() - 1; // 循环用
        while(i <= j)
        {
            int mid = (i + j) / 2;
            if (nums[mid] < target) // 目标只能在左范围内
            {
                i = mid + 1;
                if (nums[i] == target)  return {i, rightIndex};
            }
            else if (nums[mid] == target)
            {
                if (nums[mid - 1] < target) return {mid, rightIndex};
                else j = mid - 1;
            }
        }     
    }

    else    // 最后一种情况就是左右都不等于，这个时候开始找边界
    {
        leftIndex = 0;
        int lefti = 0, leftj = (nums.size() - 1) / 2;   // 负责找左边界
        int righti = (nums.size() - 1) / 2 + 1, rightj = nums.size() - 1;   // 负责找右边界

        if (nums[leftj] > target)   // 这种情况下说明都在左边
        {
            leftj--;
            while (lefti <= leftj)
            {
                int midleft = (lefti + leftj) / 2;
                if (nums[midleft] == target && nums[midleft + 1] > target)  rightIndex = midleft;
                if (nums[midleft] == target && nums[midleft - 1] < target)  leftIndex = midleft;
            }
        }
        
        return {leftIndex, rightIndex};
    }
    return {-1, -1};
}
 */