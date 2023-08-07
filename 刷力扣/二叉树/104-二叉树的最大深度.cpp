/*
题目：
- 给定一个二叉树，找出其最大深度。
- 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明: 叶子节点是指没有子节点的节点。

思路：
- 递归；
*/
#include "../headfile/io_for_leetcode.h"
using namespace std;

int maxDepth(TreeNode* root)
{
    if (root == nullptr)    return 0;
    if (!root->left && !root->right)    return 1;
    
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

int main()
{
    input input104;
    auto input_vec = input104.input_vector();
    
    TreeNode* root = buildTreeWithVec(input_vec);  // 默认参数是0

    cout << maxDepth(root) << endl;

    return 0;
}