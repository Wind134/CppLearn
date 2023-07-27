/* 
题目：
- 给定一个数组array和一个目标值target
- 元素存在则返回位置，元素不存在则返回该元素应该
- 插入的位置，思路简单，二分即可
*/
#include "../headfile/io_for_leetcode.h"
using namespace std;

int searchInsert(const vector<int>& nums, int target) 
{
    int left = 0, right = nums.size() - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] == target)    return mid;
        else if (nums[mid] > target)    right = mid - 1;
        else left = mid + 1;
    }
    
    if (left != nums.size())
    {
       return left;
    }
    else    return nums.size();
    
}

int main()
{
    input input35;
    auto array = input35.input_vector();

    int target;
    cin >> target;

    int result = searchInsert(array, target);

    cout << result << endl;

    return 0;
}