/* 给定一个旋转后的数组，找到一个target的值的下标
 * 要求logn的时间复杂度，关键是不是只需要确定是从
 * 哪个下标开始旋转的呢？
 * 假设我们根据常规的思路定位到了mid
 * 只是需要考虑到两个奇葩的特殊情况：一是以数组最后一个下标旋转
 * 此时整个数组还是有序，常规二分即可
 * 还有就是大小为1的情况，对边界的误判在这题上纠结了许久
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int search(const vector<int>& nums, const int target) 
{
    if (nums.size() == 1)
    {
        if(nums[0] == target)   return 0;
        else return -1;
    }
    
    int i = 0, j = nums.size() - 1;

    while (i <= j)
    {
        int mid = (i + j) / 2;
        if (nums[mid] == target)    return mid;
        int origini = i;    // 保存初始的i
        int originj = j;    // 保存初始的j
        // 整个区间有序的情况，这个最简单了
        if (nums[origini] <= nums[mid] && nums[originj] >= nums[mid])
        {
            if (target < nums[mid]) j = mid - 1;
            else  i = mid + 1;
        }
        else if (nums[origini] <= nums[mid]) // 在左边的有序子序列，此时右边一定无序
        {
            if (target < nums[mid] && nums[origini] <= target)  // 在区间内
            {
                j = mid - 1;
                if (nums[origini] == target)    return origini;
            }
            else i = mid + 1;
        }
        else if (nums[originj] >= nums[mid]) // 目标值在右边的有序子序列范围，此时左边一定无序
        {
            if (target > nums[mid] && nums[originj] >= target)
            {
                i = mid + 1;
                if (nums[originj] == target)    return originj;
            }
            else j = mid - 1;
        }
    }
    return -1;
}
int main()
{
    vector<int> array;
    int data;

    int target;
    while (cin >> data)
    {
        array.push_back(data);
        if (cin.get() == '\n')  break;
    }

    cin >> target;

    cout << search(array, target) << endl;

    for (const auto& num : array)
    {
        cout << num << " " ;
    }

    return 0;
}