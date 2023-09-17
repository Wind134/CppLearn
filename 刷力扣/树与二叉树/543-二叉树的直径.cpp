/*
题目：
- 给你一棵二叉树的根节点，返回该树的直径。
- 二叉树的直径是指树中任意两个节点之间最长路径的长度。
- 这条路径可能经过也可能不经过根节点root。
- 两节点之间路径的长度由它们之间边数表示。


思路：深度优先搜索
- 对于每个结点，通过深度判断直径的大小信息
*/
#include "../headfile/io_for_leetcode.h"
using namespace std;

int res = 0;

int get_length(TreeNode* root) {
    if (!root)  return 0;

    int left_height = get_length(root->left);
    int right_height = get_length(root->right);

    res = max(res, left_height + right_height);

    return max(left_height, right_height) + 1;
}

int diameterOfBinaryTree(TreeNode* root) {
    if (!root)  return 0;

    get_length(root);

    return res;
}

int main() {
   input input543;
   auto vec = input543.input_vector();

   auto root = buildTreeWithVec(vec);

   cout << diameterOfBinaryTree(root) << endl;

   return 0;
} 