/* 
* 给定一个二叉树，找出其最大深度。
* 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

* 说明: 叶子节点是指没有子节点的节点。
*/
#include <iostream>
#include "../headfile/TreeNode.h"
using namespace std;

int maxDepth(TreeNode* root)
{
    if (root == nullptr)    return 0;
    if (!root->left && !root->right)    return 1;
    
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
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

    auto result = maxDepth(root);

    cout << result << endl;

    return 0;
}