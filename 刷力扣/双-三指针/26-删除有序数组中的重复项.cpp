/*
题目：
- 一个升序排列的数组nums，请你原地删除重复出现的元素，使每个元素只出现一次，返回删除后数组的新长度。
- 元素的相对顺序应该保持一致。然后返回nums中唯一元素的个数。


思路：
- 每删除一个元素，后面都要向前移动一个元素，这种做法时间复杂度较高
- 考虑采用双指针法，效率更高
*/
#include "../headfile/io_for_leetcode.h"
#include <algorithm>
using namespace std;

int removeDuplicates(vector<int>& nums)
{
    int size = nums.size();
    if (size < 2) 
    {
        return size;
    }
    int left = 0;   // 左指针

    int right = left + 1;
    while (right < size)
    {
        if (nums[left] == nums[right])  right++;
        else
        {
            nums[++left] = nums[right];
            right++;
        }
    }
    nums.erase(nums.begin() + left + 1, nums.end());
    return left + 1;
}

int main()
{
    input input26;
    auto vec = input26.input_vector();
    int k = removeDuplicates(vec);

    cout << k << endl;
    
    return 0;
}