/*
题目：
- 给定一个包含红色、白色和蓝色、共n个元素的数组nums，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
- 我们使用整数0、1和2分别表示红色、白色和蓝色。(也就是说，整个数组都只有这三个数字)
- 必须在不使用库内置的sort函数的情况下解决这个问题。

Notes：本质上就是要求我们实现一遍排序算法，那就再手写一遍归并吧

归并排序的思路是什么？
- 针对一个序列，拆分出两个子序列array1 和 array2
- 想办法让这两个子序列有序，然后合并这两个有序子序列，然后整个序列也就有序了

那怎么让这两个子序列有序呢？针对每个子序列递归处理，处理到最后，一定会变成一个有序子序列(因为只有一个元素了)
因此归并本质上就是递归

- 后面仔细想想，其实并不怎么需要用专门的排序算法，就三种数而已，迭代处理两次即可；
*/
#include "../headfile/io_for_leetcode.h"
using namespace std;

void sortColors(vector<int>& nums)
{
    int index = 0;  // index表示的是头部范围中最后一个0后面的那个位置，初始值为0

    for (int i = 0; i < nums.size(); i++)   // 排所有的0，
    {
        if (nums[i] == 0)
        {
            swap(nums[index], nums[i]);
            index++;
        }
    }

    // 经过上面一轮，所有的0排完了
    for (int i = index; i < nums.size(); i++)
    {
        if (nums[i] == 1)
        {
            swap(nums[index], nums[i]);
            index++;
        }
    }
    
    // 1也排完了，结束
}


int main()
{
    input input75;
    auto input_vec = input75.input_vector();
    sortColors(input_vec);
    output output75;
    output75.output_array(input_vec);

    return 0;
}