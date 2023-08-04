/*
题目：
- 给你一个有序数组nums，请你原地删除重复出现的元素，使得出现次数超过两次的元素只出现两次，返回删除后数组的新长度。

思路：
- 第一反应的方案是使用单指针法，但是这样会造成重复移动，效率更低
- 因此尝试采用双指针法，具体的方案步骤就是，双指针的第一个指针指向元素头
- 第二个指针指向第一个不同的元素，一旦两个指针的大于2，进行清除处理
*/
#include "../headfile/io_for_leetcode.h"
using namespace std;

int removeDuplicates(vector<int>& nums)
{
    int left = 0;   // 移动的索引，这是左指针(索引)
    int right = 0;  // 移动的索引，这是右指针(索引)
    while(right < nums.size())  // 基于右指针的移动去循环
    {
        if(nums[right] == nums[left])  // 如果相等，右指针持续右移
        {
            right++;
            if (right == nums.size() && right - left > 2)   nums.erase(nums.begin() + left + 2, nums.begin() + right);  // 删除多余的元素
        }
        else    // 判断左右指针相隔的距离，到了这里，right指向的一定不再是跟之前相等的那个元素了
        {
            if (right - left > 2)   // 如果出现的次数超过两次
            {
                nums.erase(nums.begin() + left + 2, nums.begin() + right);  // 删除多余的元素

                // 由于删除之后，由于元素减少，因此right的元素个数会发生改变，减少的个数为right - left - 2
                // int less = right - left - 2;
                right = left + 2;  // right指向的还是那个不一样的元素 
            }

            left = right;   // 更新left
        }
    }

    return nums.size();
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