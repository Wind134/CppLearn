/*
题目：
- 整数数组nums按升序排列，数组中的值互不相同。
- 在传递给函数之前，nums在预先未知的某个下标k(0 <= k < nums.length)上进行了旋转，使数组变为：
- [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]](下标从0开始计数)。
- 例如，[0,1,2,4,5,6,7]在下标3处经旋转后可能变为[4,5,6,7,0,1,2]。
- 给你旋转后的数组nums和一个整数target，如果nums中存在这个目标值target，则返回它的下标，否则返回-1。
- 你必须设计一个时间复杂度为O(log n)的算法解决此问题。

思路：核心点在于判断逆序的个数，以及选择旋转的位置
- 第一个特殊位置在于选择了第一个位置(这个时候相当于没有旋转)
- 通过定义我们不难理解，旋转后的数列仅有一个位置存在逆序，假设[nums[i], nums[i + 1]]是逆序：
- 显然从nums[i]开始往左是有序序列，从nums[i + 1]开始往右是有序序列，那就可以接着二分
- 出现在右边的子序列的值一定是整体都要小于左边的子序列的，此外从上面的式子可以看出，相邻的两个数如果有序，那么一定出现在两个有序子序列中的某一个
- 不论在哪一个，都不影响二分的法则

- 以下是代码精简部分，对于这个旋转数组而言，最左边的那个值一定是有序序列的一部分，最右边那个值也同理
*/
#include "../headfile/io_for_leetcode.h"
#include <algorithm>
using namespace std;

int search(const vector<int>& nums, int target) 
{
    if (nums.size() == 1)
    {
        if(nums[0] == target)   return 0;
        else return -1;
    }
    
    int left = 0, right = nums.size() - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] == target)    return mid;
        if (nums[0] <= nums[mid]) { // mid属于左边部分的有序区间
            if (nums[0] <= target && target < nums[mid])    right = mid - 1;   // 只可能出现在这段区间的左部分
            else left = mid + 1;
        }
        else {  // 在右半部分的有序区间
            if (nums[nums.size() - 1] >= target && nums[mid] < target)  left = mid + 1;
            else    right = mid - 1;
        }    
    }

    return -1;
    
}
int main()
{
    input input33;
    auto array = input33.input_vector();
    cout << "Input the target: ";
    int target;
    cin >> target;

    cout << search(array, target) << endl;

    return 0;
}