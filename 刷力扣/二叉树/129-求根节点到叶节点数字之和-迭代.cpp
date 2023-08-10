/*
题目：
- 给你一个二叉树的根节点root，树中每个节点都存放有一个0到9之间的数字。
- 每条从根节点到叶节点的路径都代表一个数字：
- 例如，从根节点到叶节点的路径1 -> 2 -> 3表示数字 123。
- 计算从根节点到叶节点生成的 所有数字之和。

思路：
- 迭代的做法主要的依据是广度优先算法；
- 一层一层判断，如果到了叶节点这一层，就去处理结果的值；
- 如果并非叶节点，那就将这个结点所代表的数入队；
*/
#include "../headfile/io_for_leetcode.h"
#include <queue>
using namespace std;

int sumNumbers(TreeNode* root) {
    if (!root)  return 0;
    queue<TreeNode*> nodeQue;
    queue<int> numQue;
    int result = 0;
    nodeQue.push(root);
    numQue.push(root->val);
    while (!nodeQue.empty()) {
        auto temp_node = nodeQue.front();   // 队先进先出
        int num = numQue.front();
        nodeQue.pop();
        numQue.pop();
        if (!temp_node->left && !temp_node->right)  result += num;
        else {
            if (temp_node->left) {
                nodeQue.push(temp_node->left);
                numQue.push(10 * num + temp_node->left->val);
            }

            if (temp_node->right) {
                nodeQue.push(temp_node->right);
                numQue.push(10 * num + temp_node->right->val);
            }
        }
    }    
    return result;
}

int main() {
    input input129;
    auto vec = input129.input_vector();

    auto root = buildTreeWithVec(vec);
    cout << sumNumbers(root) << endl;

    return 0;
}