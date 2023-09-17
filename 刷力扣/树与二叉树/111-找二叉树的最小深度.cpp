/*
题目：
- 给定一个二叉树，找出其最小深度。
注：最小深度是从根节点到最近叶子节点的最短路径上的节点数量。


思路：
- 一个简单而直观的递归；
*/
#include "../headfile/io_for_leetcode.h"
#include <algorithm>
using namespace std;

int minDepth(TreeNode* root)
{
    if (!root)  return 0;
    if (!root->left)    return minDepth(root->right) + 1;
    if (!root->right)    return minDepth(root->left) + 1;

    return min(minDepth(root->left), minDepth(root->right)) + 1;
}

int main()
{
    input input111;
    
    vector<int> vec = input111.input_vector();

    TreeNode* root = buildTreeWithVec(vec);

    cout << minDepth(root) << endl;

    return 0;
}