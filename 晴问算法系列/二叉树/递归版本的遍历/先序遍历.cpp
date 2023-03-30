/* 有一个误区，并不需要自己按照指针去严格建立新树，因为数组构成了一定的地址关系，不需要复杂化 */
#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int lnum, rnum;
};

void preOrder(const vector<Node>& nums, int i, bool tag)
{
    if (tag)
    {
        cout << i;
        tag = false;    // 专门用来处理最后一位的空格
    }    
    else cout << " " << i;          
    if (nums[i].lnum != -1)
    {
        preOrder(nums, nums[i].lnum, tag);
    }
    if (nums[i].rnum != -1)
    {
        preOrder(nums, nums[i].rnum, tag);
    }    
}


int main()
{
    int n;
    cin >> n;
    vector<Node> nums(n);   // 定义一个数组
    Node data;  // 处理输入的结点
    for (int i = 0; i < n; i++)     // 每个结点都保存完毕
    {
        cin >> data.lnum >> data.rnum;
        nums[i] = data;
    }
    preOrder(nums, 0, true);
    return 0;
}