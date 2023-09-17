/*
题目：
- 给你一个二叉树的根节点root，检查它是否轴对称。

思路：
- 对每个结点结点的左右两颗子树做判断；
*/
#include "../headfile/io_for_leetcode.h"
using namespace std;

bool isEqual(TreeNode* node1, TreeNode* node2)
{
    if (!node1 && !node2)  return true;     // 如果两个节点都是空，认为是相等的
    
    if (node1 && node2)     // 如果都不是空，则判断子节点
    {
        bool result1 = isEqual(node1->left, node2->right);  // 判断左节点的左孩子与右节点的右孩子
        if (!result1)   return false;
        bool result2 = isEqual(node1->right, node2->left);  // 判断左节点的右孩子和右节点的左孩子
        if (!result2)   return false;
        return node1->val == node2->val && result1 && result2;
    }

    // 其他情况就是false
    return false;
}

bool isSymmetric(TreeNode* root)
{
    if (!root)  return true;
    else if (root->left && root->right) return isEqual(root->left, root->right);     // 从根节点开始
    else return false;
}

int main()
{
    input input101;
    auto input_vec = input101.input_vector();
    
    TreeNode* root = buildTreeWithVec(input_vec);  // 默认参数是0

    cout << boolalpha << isSymmetric(root) << endl;
}