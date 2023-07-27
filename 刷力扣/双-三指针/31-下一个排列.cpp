/* 
题目：给定你一个排列，要求找这个排列的下一个排列(更大的字典序)


思路：
- 假设给定了一个序列，我们第一反应应该是观察这个序列的有序性，为什么这么说：
    -- 假设[1 2 3 4 5]，在这个序列中，全部按照升序排列，那么下一个排列，我们希望这个排列的字典序变大，但变大的幅度要尽可能小
    -- 那么下一个排列应该是[1 2 3 5 4]，5 - 4的字典序差值是1
    -- 再下一个排列应该是[1 2 5 4 3],5 - 3的字典序差值是2
    -- 这里最核心的问题是要去理解下一个排列，不在于算法本身
 
- 最终绝杀思路：从右往前找，找到第一个升序的相邻元素对(i,j)，这就说明从j开始，后续的一定都是逆序
- 从[j, end)这个范围，继续从右往左找到第一个满足nums[i] < num[j]的元素，这样就保证了范围绝对靠右
- 找到上述那个元素之后，交换两个值，交换之后我们可以断定[j, end]一定逆序，进行翻转，则升序，问题解决

- 翻转序列是双指针

*/
#include "../headfile/io_for_leetcode.h"
#include <algorithm>
using namespace std;


void nextPermutation(vector<int>& nums)
{
    for (int i = nums.size() - 1; i >= 1; i--)
    {
        if (nums[i] > nums[i-1])
        {
            for(int j = nums.size() - 1; j >= i; j-- )
            {
                if (nums[j] > nums[i - 1])
                {
                    swap(nums[i-1], nums[j]);
                    
                    reverse(nums.begin() + i, nums.end());  // reverse是内置函数
                    return;
                }
            }
        } 
    }

    reverse(nums.begin(), nums.end());  
}

int main()
{
    input input31;
    auto array = input31.input_vector();

    nextPermutation(array);

    output output31;
    output31.output_array(array);

    return 0;
}