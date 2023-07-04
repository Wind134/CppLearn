/* 给你一个二叉树的根节点root，检查它是否轴对称。*/
#include <iostream>
#include <vector>
#include "../headfile/TreeNode.h"
using namespace std;

bool isEqual(TreeNode* node1, TreeNode* node2)
{
    if (!node1 && !node2)  return true;     // 如果两个节点都是空，认为是相等的
    
    if (node1 && node2)     // 如果都不是空，则判断子节点
    {
        bool result1 = isEqual(node1->left, node2->right);  // 判断左节点的左孩子与右节点的右孩子
        bool result2 = isEqual(node1->right, node2->left);  // 判断左节点的右孩子和右节点的左孩子
        return node1->val == node2->val && result1 && result2;
    }

    // 其他情况就是false
    return false;
}

bool isSymmetric(TreeNode* root)
{
    return isEqual(root, root);     // 从根节点开始
}

int main()
{
    cout << "Please input the value of every node(-1 represents null): ";
    vector<int> root_array;
    int input_data;
    while (cin >> input_data)
    {
        root_array.push_back(input_data);
        if(cin.get() == '\n')   break;
    }
    
    TreeNode* root = buildTreeWithVec(root_array);  // 默认参数是0

    cout << boolalpha << isSymmetric(root) << endl;
}