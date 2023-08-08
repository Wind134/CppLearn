/*
题目：
- 给你二叉树的根节点root和一个表示目标和的整数targetSum。
- 判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和targetSum。如果存在，返回true；否则，返回false。


思路：
- 每遍历一个节点，target就相应减去该节点对应的值，访问完叶节点后，看是否为零；
- 可以引入一个外部变量降低时间复杂度；
*/
#include "../headfile/io_for_leetcode.h"
using namespace std;

// int node_val_sum = 0;
// int tag_result = false;

bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root)  return false;

    if (!root->left && !root->right)    // 这是最后退出的临界点
    {
        if (root->val == targetSum)  return true;
    }

    if (root->left)
    {
        bool res_left = hasPathSum(root->left, targetSum - root->val);
        if (res_left) return true;  // 这一步保证找到了之后就不会再往下继续执行
    }

    if (root->right)
    {
        bool res_right = hasPathSum(root->right, targetSum - root->val);
        if (res_right) return true;
    }

    return false;
}

int main()
{
    input input112;
    auto vec = input112.input_vector();

    TreeNode* root = buildTreeWithVec(vec); // 根节点

    int target;
    cout << "Please input the target value: ";
    cin >> target;

    cout << boolalpha << hasPathSum(root, target) << endl;
    return 0;
}