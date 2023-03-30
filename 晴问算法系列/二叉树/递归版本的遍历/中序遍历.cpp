/* 有一个误区，并不需要自己按照指针去严格建立新树，因为数组构成了一定的地址关系，不需要复杂化 */
/* 处理空格的思维好像不太一样了：引用！引用！ */
#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int lnum, rnum;
};

void inOrder(const vector<Node>& nums, int i, bool& tag)    // tag用来处理空格
{
    if (nums[i].lnum != -1)
    {
        inOrder(nums, nums[i].lnum, tag);
    }
    if (tag)
    {
        cout << i;
        tag = false;    // 专门用来处理最后一位的空格
    }    
    else cout << " " << i;      
    
    if (nums[i].rnum != -1)
    {
        inOrder(nums, nums[i].rnum, tag);
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
    bool tag = true;
    inOrder(nums, 0, tag);
    return 0;
}