/*
题目：
- 将有序数组转换为二叉搜索树，要求这颗树高度平衡；

思路：完蛋，怎么处理这个平衡呢？
- 由于给定的是一个有序数组，因此必定是一个中序遍历的结果
- 那针对初始序列，我们取有序数组的中间节点mid作为根节点，然后数组一分为二
- 以mid为根节点，我们就可以确认到一点，这棵树一定是平衡的，关于这一点的证明，Leetcode 1382题有详细说明
- 然后，其中[0, mid - 1]为左子树范围，[mid + 1, size - 1]为右子树范围，我们对两颗子树处以同样的策略
- 即可
*/
#include "../headfile/io_for_leetcode.h"
using namespace std;

TreeNode* get_balance_tree(const vector<int>& nums, int left, int right) {
    if (left > right)   return nullptr;
    int mid = (left + right) / 2;
    TreeNode* root = new TreeNode(nums[mid]);

    root->left = get_balance_tree(nums, left, mid - 1);
    root->right = get_balance_tree(nums, mid + 1, right);

    return root;
}


TreeNode* sortedArrayToBST(const vector<int>& nums) {
    return get_balance_tree(nums, 0, nums.size() - 1);
}

int main()
{
    input input108;
    auto input_array = input108.input_vector();

    auto result = sortedArrayToBST(input_array);

    preOrderTraversal(result);
    cout << endl;
}