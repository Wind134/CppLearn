/*
- 给你一个二叉树的根节点root，树中每个节点都存放有一个0到9之间的数字。
- 每条从根节点到叶节点的路径都代表一个数字：

例如，从根节点到叶节点的路径1 -> 2 -> 3表示数字 123。
计算从根节点到叶节点生成的 所有数字之和。

叶节点 是指没有子节点的节点。

- 从根节点开始，依次访问元素，将每一个访问到的元素入栈(栈的元素为节点类型)，如果栈顶元素的左孩子为空，则入栈右孩子
- 若都为空，说明到了叶子节点，此时开始处理数值，依照这原则，最终访问完毕所有的叶节点

尝试递归做法
*/
#include "../headfile/io_for_leetcode.h"
#include "../headfile/TreeNode.h"
using namespace std;
int result = 0;

void dfs(TreeNode* root, int start)
{
    if (!root->left && !root->right) {
        int new_start = 10 * start + root->val;
        result += new_start;
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