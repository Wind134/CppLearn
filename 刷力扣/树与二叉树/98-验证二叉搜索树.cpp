/*
题目：
- 给你一个二叉树的根节点root，判断其是否是一个有效的二叉搜索树。

二叉搜索数的定义：
- 二叉搜索树是一种特殊的二叉树，它的每个节点都有一个值，且每个节点的左子树中所有节点的值都小于该节点的值，而右子树中所有节点的值都大于该节点的值。

思路：
- 二叉搜索树中序遍历的结果应该是一个严格递增的数
*/
#include "../headfile/io_for_leetcode.h"
using namespace std;

long value = LONG_MIN;

bool isValidBST(TreeNode* root)
{
    if (!root)  return true;
    bool res_left = isValidBST(root->left);

    if (root->val > value)  value = root->val;
    else return false;
    
    bool res_right = isValidBST(root->right);
    return res_left && res_right;
}


int main()
{
    input input98;

    auto vec = input98.input_vector();

    TreeNode* root = buildTreeWithVec(vec);

    cout << boolalpha << isValidBST(root) << endl;
    
    return 0;
}