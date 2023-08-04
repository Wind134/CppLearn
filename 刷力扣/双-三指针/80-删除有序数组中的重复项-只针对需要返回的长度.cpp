/*
题目：
- 给你一个有序数组nums，请你原地删除重复出现的元素，使得出现次数超过两次的元素只出现两次，返回删除后数组的新长度。

思路：
- 不对数组做erase操作，而是通过一些算法更新其长度
- 主要策略是通过快慢指针实现
*/
#include "../headfile/io_for_leetcode.h"
using namespace std;

int removeDuplicates(vector<int>& nums)
{
    if (nums.size() < 2) return nums.size();

    int slow = 2;   // 移动的索引，这是慢指针(索引)
    int fast = 2;   // 移动的索引，这是快指针(索引)

    // 从代码可以看出，两个指针初始位置相同
    while(fast < nums.size())  // 基于快指针的移动去循环
    {
        if(nums[slow - 2] != nums[fast])  // slow的两个长度以内都是安全长度
        {
            nums[slow] = nums[fast];      // 更新slow位置的数组值
            ++slow;
        }
        fast++;
    }

    return slow;
}

int main()
{
    input input80;
    auto input_vec = input80.input_vector();

    auto result = removeDuplicates(input_vec);

    cout << "The final length of array: " << result << endl;

    output output80;
    output80.output_array(input_vec);

    return 0;
}