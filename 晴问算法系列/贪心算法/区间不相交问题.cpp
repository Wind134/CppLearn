/* 给定n个开区间，从中选择尽可能多的开区间，使得这些开区间
两两之间并无交集
思路：要尽可能选择多的区间，那也就是尽可能让本区间尽可能早结束，这样
下一个区间能选择的范围会尽可能的轻松一些
给定了两个数组，我们对比一下首端点和尾端点即可，我们要选择尽可能多的符合条件的区间
我们选择两两区间，这两个区间进行检查，最终一定会从这两个区间中选择一个作为进行下一对比的基准区间
那从贪心的策略角度来说这个问题，肯定我们希望留下的是左端点更大的那个区间，这样会区间交叉的可能会更小
因此代码：
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct inteval
{
    /* data */
    int left, right;
};
bool cmp(const inteval& a, const inteval& b)
{
    if (a.left != b.left)    return a.left > b.left;    // 按左端点越大越好
    else return a.right < b.right;  // 右端点越小越好
}

int main ()
{
    int nums;
    cin >> nums;
    vector<inteval> intevals(nums);
    for (int i = 0; i < nums; i++)
    {
        cin >> intevals[i].left >> intevals[i].right;
    }
    sort(intevals.begin(), intevals.end(), cmp);
    int count = 1;    // 不管怎么样先选中最大的区间，准没错
    int lastL = intevals[0].left;   // 先定义变量保存第一个左端点，省得在循环中重定义
    for (int i = 1; i < nums; i++)
    {
        if (lastL >= intevals[i].right)
        {
            count++;
            lastL = intevals[i].left;
        }
    }
    cout << count << endl;
}