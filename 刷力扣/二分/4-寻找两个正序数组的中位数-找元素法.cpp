// 两个数组已经确定正序
// 想办法将两个有序序列组合在一起

#include "../headfile/io_for_leetcode.h"
using namespace std;


double findMedianSortedArrays(const vector<int>& nums1, const vector<int>& nums2)
{
    int size1 = nums1.size(), size2 = nums2.size();         // 分别保存两个数组的长度
    int length = size1 + size2;
    int num1Index = 0, num2Index = 0;       // 移动的初始位置在首位
    int value1 = 0, value2 = 0;             // 分别保存每次循环的值，之所以设置两个是考虑了偶数的情形
    for (int i = 0; i <= length /2; i++)                     // 这部分需要循环处理多次
    {
        value1 = value2;    // 保存上一轮循环的值
        if (num1Index < size1 && num2Index < size2)
        {
            if (nums1[num1Index] < nums2[num2Index])    value2 = nums1[num1Index++];    // 更新本轮循环的值
            else    value2 = nums2[num2Index++];
        }
        else if (num1Index < size1 && num2Index == size2)
        {
            value2 = nums1[num1Index++];
        }
        else if (num1Index == size1 && num2Index < size2)
        {
            value2 = nums2[num2Index++];
        }
    }
    
    if (length % 2)     // 如果新数组长为奇数
    {
        return value2;
    }                 
    else    return (value1 + value2) / 2.0;        
}

int main()
{
    input input4_1, input4_2;
    auto vec1 = input4_1.input_vector();
    auto vec2 = input4_2.input_vector();
    double value = findMedianSortedArrays(vec1, vec2);
    cout << "中位数的值为：" << value << endl;
    return 0;
}
