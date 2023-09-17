/*
题目：
- 给定两个整数数组preorder和inorder，其中preorder是二叉树的先序遍历，inorder是同一棵树的中序遍历，请构造二叉树并返回其根节点。

思路：
- 优化的方向是将索引单独提出来，然后对inorder自身建立一个映射
*/
#include "../headfile/io_for_leetcode.h"
#include <algorithm>
#include <map>
using namespace std;

// 这部分用来建立映射，将中序数组中的值与下标索引相互对应
map<int, int> elem_index;

TreeNode* splitByIndex(const vector<int>& preorder, int begin_index_pre, int end_index_pre,  // pre中的起始位
int begin_index_in, int end_index_in)    // 与之对应的，中序遍历中的起始位与结束位
{
    // 临界点
    if (begin_index_pre >= preorder.size() || begin_index_pre > end_index_pre) return nullptr;

    if (begin_index_pre == end_index_pre)   return (new TreeNode(preorder[begin_index_pre]));

    TreeNode* root = new TreeNode(preorder[begin_index_pre]);

    int index = elem_index[preorder[begin_index_pre]];   // 获取先序遍历中根节点的索引，以获取左右子树的索引

    // 从这里可以知道，索引(begin_index_pre + 1) ~ (index - begin_index_in + begin_index_pre)是左子树；
    // (index - begin_index_in + begin_index_pre + 1) ~ (end_index_pre)是右子树；
    root->left = splitByIndex(preorder, begin_index_pre + 1, index - begin_index_in + begin_index_pre, begin_index_in, index - 1);
    root->right = splitByIndex(preorder, index - begin_index_in + begin_index_pre + 1, end_index_pre, index + 1, end_index_in);

    return root;
} 

TreeNode* buildTree(const vector<int>& preorder, const vector<int>& inorder) {
    if (preorder.size() == 0)   return nullptr; // 用哪个去表示size应该都行，反正大小必定一致

    if (elem_index.empty()) {   // 可以为后面查找索引实现O(1)的复杂度
        for (int i = 0; i < inorder.size(); i++)
            elem_index[inorder[i]] = i;
    }

    int size = preorder.size();

    TreeNode* root = splitByIndex(preorder, 0, size - 1, 0, size - 1);

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