/* 
* 给定n个非负整数表示每个宽度为1的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
* 我们需要雨水能够成功储存，那么就需要满足的条件是什么呢？
* 找到一高一低的两根柱子，这两根柱子的距离要尽可能远，这一高一低中的低不包括0
* 假设此刻的索引在index，我接下来依次遍历这个数组，找到大于等于该索引位置的数，如果没有这么一个数
* 那就找比他小的数
*/
#include <iostream>
#include <vector>
using namespace std;

int cal_column_area(const vector<int>& height, int start, int end)  // 该函数计算圆柱所占面积
{
    int sum = 0;
    for (int i = start + 1; i != end; i++)
    {
        sum += height[i];
    }
    return sum;
}

int biggest(const vector<int>& height, int start)
{
    int targetIndex = -1;
    int maxValue = -1;
    for (int i = start + 1; i < height.size(); i++)
    {
        if (height[i] > maxValue)
        {
            maxValue = height[i];
            targetIndex = i;
        }
    }
    return targetIndex;
}

int trap(const vector<int>& height)
{
    int initIndex = 0;
    int result = 0;

    while (initIndex < height.size())
    {
        bool tag = false;   // 判断for循环中的if条件是否被成功执行
        if (initIndex == height.size() -1)  break;
        for (int i = initIndex + 1; i < height.size(); i++)
        {
            if (height[i] >= height[initIndex])
            {
                if (i - initIndex - 1 != 0)
                    result += height[initIndex] * (i - initIndex - 1) - cal_column_area(height, initIndex, i);
                initIndex = i;  // 起始索引更新
                tag = true;     // 说明，我已经找到了更大的那个值
                break;  // 跳出循环
            }    
        }
        if (!tag)   // 没找到，那就只能找到更小的那个，在更小的那部分剩余元素中找到的最大那个元素
        {
            int targetIndex = biggest(height, initIndex);
            if(targetIndex - initIndex - 1 != 0)
                result += height[targetIndex] * (targetIndex - initIndex - 1) - 
                        cal_column_area(height, initIndex, targetIndex);
            initIndex = targetIndex;            
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