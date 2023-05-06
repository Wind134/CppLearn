/* 给定一个长度为n的整数数组height。
有n条垂线，第i条线的两个端点是(i, 0)和(i, height[i])。
找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水 */
// 思路：S(i, j) = min(h[i], h[j]) * (j - i)
// 长度更长的那块木板的index向内移动，那么S是一定会更小的
// 长度更短的那块木板的index向内移动，那么S是可能变大的，因为min(h[i], h[j])可能增大

#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

int maxArea(const vector<int>&);

int main()
{
    int elem;
    vector<int> height;
    while (cin >> elem)
    {
        height.push_back(elem);
    }
    cout << maxArea(height) << endl; 
    return 0;
}

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