/* 给定两个整数数组preorder和inorder，其中preorder是二叉树的先序遍历，inorder是同一棵树的中序遍历，请构造二叉树并返回其根节点。*/
#include <iostream>
#include <vector>
#include <algorithm>
#include "../headfile/TreeNode.h"
using namespace std;


TreeNode* buildTree(const vector<int>& preorder, const vector<int>& inorder)
{
    if (preorder.size() == 0)   return nullptr; // 用哪个去表示size应该都行，反正大小必定一致
    auto pos = find(inorder.begin(), inorder.end(), preorder[0]);

    int index = pos - inorder.begin();
    TreeNode* root = new TreeNode(preorder[0]); // 确立根节点

    vector<int> sub_pre_node_left(preorder.begin() + 1, preorder.begin() + index + 1);
    vector<int> sub_pre_node_right(preorder.begin() + index + 1, preorder.end());
    vector<int> sub_in_node_left(inorder.begin(), inorder.begin() + index);
    vector<int> sub_in_node_right(pos + 1, inorder.end());
    root->left = buildTree(sub_pre_node_left, sub_in_node_left);
    root->right = buildTree(sub_pre_node_right, sub_in_node_right);

    return root;
}

int main()
{
    vector<int> input_array1;
    vector<int> input_array2;

    int input_data;
    while(cin >> input_data)
    {
        input_array1.push_back(input_data);
        if (cin.get() == '\n')  break;
    }

    while(cin >> input_data)
    {
        input_array2.push_back(input_data);
        if (cin.get() == '\n')  break;
    }
    
    auto result = buildTree(input_array1, input_array2);

    preOrderTraversal(result);

    cout << endl;

    return 0;
}