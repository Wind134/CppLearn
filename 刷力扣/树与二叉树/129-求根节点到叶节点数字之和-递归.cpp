/*
题目：
- 给你一个二叉树的根节点root，树中每个节点都存放有一个0到9之间的数字。
- 每条从根节点到叶节点的路径都代表一个数字：
- 例如，从根节点到叶节点的路径1 -> 2 -> 3表示数字 123。
- 计算从根节点到叶节点生成的 所有数字之和。

思路：递归的做法
- 我们要获取实际数字，针对二叉树的每一层，这一层结点的实际数字 = 10 * 上一层结点的实际数字 + 这一层本结点的实际数字；
- 针对每个结点这么处理即可
*/
#include "../headfile/io_for_leetcode.h"
using namespace std;
int result = 0;

void dfs(TreeNode* root, int start)
{
    if (!root->left && !root->right) {
        int new_start = 10 * start + root->val;
        result += new_start;    // 处理result的值
        return;
    }    
     if (root->left) {
        int new_start = 10 * start + root->val;
        dfs(root->left, new_start);
    }
    if (root->right) {
        int new_start = 10 * start + root->val;
        dfs(root->right, new_start);
    }
}

int sumNumbers(TreeNode* root) {
    dfs(root, 0);
    return result;
}

int main() {
    input input129;
    auto vec = input129.input_vector();

    auto root = buildTreeWithVec(vec);
    cout << sumNumbers(root) << endl;

    return 0;
}