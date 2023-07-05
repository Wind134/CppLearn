/*
给定两个整数数组inorder和postorder，其中inorder是二叉树的中序遍历，postorder是同一棵树的后序遍历，请你构造并返回这颗二叉树。
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include "../headfile/TreeNode.h"
using namespace std;

// 这部分用来建立映射，将中序数组中的值与下标索引相互对应
map<int, int> elem_index;

TreeNode* splitByIndex(const vector<int>& postorder, int begin_index_post, int end_index_post,  // post中的起始位与结束位
int begin_index_in, int end_index_in)    // 中序遍历中的起始位与结束位
{
    // 临界点
    if (begin_index_post >= postorder.size() || begin_index_post > end_index_post) return nullptr;

    if (begin_index_post == end_index_post)   return (new TreeNode(postorder[begin_index_post]));

    TreeNode* root = new TreeNode(postorder[end_index_post]);

    int index = elem_index[postorder[end_index_post]];   // 获取后序遍历中根节点的索引，以获取左右子树的索引

    // 从这里可以知道，索引begin_index_post~left_end是左子树；
    // begin_index_in ~ index - 1是右子树
    int left_end = begin_index_post - 1 + index - begin_index_in;
    root->left = splitByIndex(postorder, begin_index_post, left_end, begin_index_in, index - 1);
    root->right = splitByIndex(postorder, left_end + 1, end_index_post - 1, index + 1, end_index_in);

    return root;
} 

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if (postorder.size() == 0)   return nullptr; // 用哪个去表示size应该都行，反正大小必定一致

    if (elem_index.empty()) {
        for (int i = 0; i < inorder.size(); i++)
            elem_index[inorder[i]] = i;
    }

    int size = postorder.size();

    TreeNode* root = splitByIndex(postorder, 0, size - 1, 0, size - 1);

    return root;
}

int main()
{
    vector<int> input_array1;
    vector<int> input_array2;

    int input_data;
    while(cin >> input_data) {
        input_array1.push_back(input_data);
        if (cin.get() == '\n')  break;
    }

    while(cin >> input_data) {
        input_array2.push_back(input_data);
        if (cin.get() == '\n')  break;
    }
    
    auto result = buildTree(input_array1, input_array2);

    preOrderTraversal(result);

    cout << endl;

    return 0;
}