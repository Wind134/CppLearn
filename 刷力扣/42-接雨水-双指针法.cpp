/* 
* 这个做法采用双指针的思想，优化动态规划算法所形成的空间复杂度：
* 该索引左边的最大值leftMax[index]与该索引右边最大值rightMax[index]，这两个数组的维护我们改为对leftMax与rightMax的
* 维护，leftIndex初始位置为0，rightIndex初始位置为size - 1，我们结合动态规划的思路，统计leftIndex与rightIndex处所能
* 接的雨水量，这个时候要处理的关键问题是，两个指针怎么移动呢？我们能确定哪个位置所能接的雨水量，我们就移动哪个位置；
* 如果height[leftIndex] < height[rightIndex]，那么leftMax < rightMax是必然的，那么该位置所能接的量：leftMax - height[leftIndex]
* 如果height[leftIndex] >= height[rightIndex]，那么leftMax >= rightMax，该位置：leftMax - height[rightIndex]
* 哪个位置能确定，就算哪个
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int trap(const vector<int>& height)
{
    int result = 0;
    int leftIndex = 0, rightIndex = height.size() - 1;
    int leftMax = *height.begin(), rightMax = *(height.end() - 1);
    while (leftIndex < rightIndex)
    {
        if (height[leftIndex] < height[rightIndex])
        {
            leftMax = max(leftMax, height[leftIndex]);
            result += leftMax - height[leftIndex];
            leftIndex++;
        }
        else
        {
            rightMax = max(rightMax, height[rightIndex]);
            result += rightMax - height[rightIndex];
            rightIndex--;
        }
    }
    return result;
}

int main()
{
    vector<int> input;

    int data;

    while (cin >> data)
    {
        input.push_back(data);
        if (cin.get() == '\n')
        {
            break;
        }
    }
    cout << trap(input) << endl;
}    