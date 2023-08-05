/*
题目：
- 给你两个按非递减顺序排列的整数数组nums1和nums2，另有两个整数m和n，分别表示nums1和nums2中的元素数目。
- 请你合并nums2到nums1中，使合并后的数组同样按非递减顺序排列。

思路：
- 这道题本身很简单，但我们可以尝试就地实现排序，不借助sort以及额外空间
- 我们尝试从后面往前面遍历，很一目了然
*/
#include "../headfile/io_for_leetcode.h"
using namespace std;
/**
 * @param m nums1的元素数目
 * @param n nums2的元素数目
 */
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    int index1 = m - 1; // nums1的移动指针，初始值指向nums1的最后一个元素
    int index2 = n - 1; // nums2的移动指针，初始值指向nums2的最后一个元素
    while (index1 >= 0 && index2 >= 0)
    {
        if (nums1[index1] < nums2[index2])
        {
            nums1[index1 + index2 + 1] = nums2[index2];
            index2--;
        }
        else
        {
            nums1[index1 + index2 + 1]  = nums1[index1];
            index1--;
        }
    }
    while (index2 >= 0)
    {
        nums1[index2] = nums2[index2];  // 因为此时index1成为-1了
        index2--;
    }   
}

int main()
{
    input input88_1;
    input input88_2;
    output output88;
    auto vec1 = input88_1.input_vector();
    auto vec2 = input88_2.input_vector();

    merge(vec1, vec1.size() - vec2.size(), vec2, vec2.size());

    output88.output_array(vec1);

    return 0;
    
}