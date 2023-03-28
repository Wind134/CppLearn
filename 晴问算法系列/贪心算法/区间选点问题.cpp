/* 给定n个闭区间，问最少需要确定多少个点，才能使每个闭区间中都至少存在一个点。 */

// 本质上还是求n个区间的公共区间，要求的是至少，那么我们尽可能找出多个区间的公共区间
// 即将点放在尽可能多的区间的公共区间范围内
#include <iostream>
#include <vector>   // 尽可能用vector吧以后
#include <algorithm>
using namespace std;

struct Interval
{
    int left, right;
};

bool cmp(const Interval &a, const Interval &b)  // 排序用
{
    if (a.left != b.left)   return a.left < b.left;
    else return a.right < b.right;
}

int main()
{
    int n;
    cin >> n;
    vector<Interval> intervals;
    Interval inputData;
    for (int i = 0; i < n; i++)
    {
        cin >> inputData.left >> inputData.right;
        intervals.push_back(inputData);
    }
    sort(intervals.begin(), intervals.end(), cmp);  // 排序处理
    int count = 1;  // count初始值
    int beginPoint = 0; // 起始下标，起初为0
    int temp = intervals[beginPoint].right;   // 一个临时变量，记录最小的那个端点，或者说确定满足条件的点的上限
    for (int j = 0; j < n; j++)
    {  
        temp = min(temp, intervals[j].right);   // 获取了右区间端点最小的区间的右端点
        if (intervals[j].left <= intervals[beginPoint].right && temp >= intervals[j].left)    continue;  // 没法保证端点处的特殊情况
        /* else if (intervals[j].left == intervals[beginPoint].right)
        {
            if (temp < intervals[j].left) count++;
            else continue;
        } */
        else
        {
            count++;
            beginPoint = j;
            temp = intervals[beginPoint].right; // 更改新的值
        }
        
    }
    cout << count << endl;
    return 0;
}
