/* 
给你一个二叉树的根节点root，判断其是否是一个有效的二叉搜索树。

* 二叉搜索数的定义：
- 二叉搜索树是一种特殊的二叉树，它的每个节点都有一个值，且每个节点的左子树中所有节点的值都小于该节点的值，而右子树中所有节点的值都大于该节点的值。

* 验证的难点在于，根节点的孩子节点的孩子节点是不可控因素，因此我们可以采取中序遍历的方式
*/
#include <iostream>
#include <vector>
#include "../headfile/TreeNode.h"
using namespace std;

int value = MIN_INT;    // 定义一个下限值，因为这个数是用来比较大小的

void visitBinaryTree(TreeNode* root, bool& tag)
{
    if (root == nullptr || !tag)    return;
    visitBinaryTree(root->left, tag);
    if(root->val > value)
    {
        value = root->val;
    }
    else
    {
        tag = false;
    }
    visitBinaryTree(root->right, tag);
}

bool isValidBST(TreeNode* root)
{
    if (root->left == nullptr && root->right == nullptr)    return true;
    bool result = true;
    visitBinaryTree(root, result);
    return result;
}


int main()
{
    vector<int> input;

    int input_data;

    while (cin >> input_data)
    {
        input.push_back(input_data);
        if(cin.get() == '\n')   break;
    }

    TreeNode* root = buildTreeWithVec(input, 0);

    cout << boolalpha << isValidBST(root) << endl;
    
    return 0;
}