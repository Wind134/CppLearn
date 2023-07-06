/*
- 给你二叉树的根节点root和一个表示目标和的整数targetSum。

- 判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和targetSum。如果存在，返回true；否则，返回false。

- 叶子节点是指没有子节点的节点
*/
#include "../headfile/TreeNode.h"
#include "../headfile/io_for_leetcode.h"
using namespace std;

// int node_val_sum = 0;
int tag_result = false;

bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root)  return false;

    if (!root->left && !root->right)    // 这是最后退出的临界点
    {
        if (root->val == targetSum)
        {
            tag_result = true;
            return tag_result;
        }
    }

    if (root->left && !tag_result)
    {
        hasPathSum(root->left, targetSum - root->val);
        if (tag_result) return tag_result;  // 这一步保证找到了之后就不会再往下继续执行
    }

    if (root->right && !tag_result)
    {
        hasPathSum(root->right, targetSum - root->val);
        if (tag_result) return tag_result;
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