/*
题目：
- 给定一个长度为n的整数数组height。
- 有n条垂线，第i条线的两个端点是(i, 0)和(i, height[i])。
- 找出其中的两条线，使得它们与x轴共同构成的容器可以容纳最多的水


思路：双指针法，一个指针指向长度更短的那块木板，一个指针指向长度更长的那块木板，左右指针初始位置为[0, size - 1]
- 容纳水的面积：S(i, j) = min(h[i], h[j]) * (j - i)
- 长度更长的那块木板的index向内移动，那么S是一定会更小的(好理解，长度要是更长了，j - i小了，要是更短了，都小了)
- 长度更短的那块木板的index向内移动，那么S是可能变大的，因为min(h[i], h[j])可能增大，即便(j - i)可能也变小，但整体可能会变大
- 基于上述原则不断移动指针即可

*/

#include "../headfile/io_for_leetcode.h"
#include <algorithm>
using namespace std;

int maxArea(const vector<int>& height)
{
    int left = 0, right = height.size() - 1, square = 0;
    while (left != right)
    {
        square = (height[left] < height[right])?
        max(square, (right - left) * height[left++]):
        max(square, (right - left) * height[right--]);
    }
    return square;
}

int main()
{
    input input11;
    auto vec = input11.input_vector();
    cout << maxArea(vec) << endl; 
    return 0;
}

