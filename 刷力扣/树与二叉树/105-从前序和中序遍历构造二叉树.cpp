/*
题目：
- 给定两个整数数组preorder和inorder，其中preorder是二叉树的先序遍历，inorder是同一棵树的中序遍历，请构造二叉树并返回其根节点。

思路：递归处理；
*/
#include "../headfile/io_for_leetcode.h"
#include <algorithm>
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
    input input105_1;
    input input105_2;

    vector<int> input_array1 = input105_1.input_vector();
    vector<int> input_array2 = input105_2.input_vector();
    
    auto result = buildTree(input_array1, input_array2);

    postOrderTraversal(result);

    cout << endl;

    return 0;
}