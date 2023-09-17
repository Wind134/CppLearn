/**
 * 题目：
 * 给定一个二叉树的根节点root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
 * 更具体一点，是在同一层能看到的最右的结点，因此用层序遍历去模拟过程是比较方便的
 * 
 * 
 * 思路：
 * 层序遍历
 */
#include "../headfile/io_for_leetcode.h"
using namespace std;


vector<int> rightSideView(TreeNode* root) {
    vector<int> res;
    if (!root)  return res;

    queue<TreeNode*> q_info;

    q_info.push(root);

    while (!q_info.empty()) {
        size_t len = q_info.size();
        for (size_t i = 0; i < len; ++i) {
            auto node = q_info.front();
            if (i == 0) res.push_back(node->val);
            if (node->right) q_info.push(node->right);  // 右结点先入队
            if (node->left) q_info.push(node->left);    // 左节点再入队
            q_info.pop();   // 将目标值出队
        }
    }

    return res;
}

int main() {
    input input199;
    auto input_vec = input199.input_vector();

    auto root = buildTreeWithVec(input_vec);
    
    output output199;
    output199.output_array(rightSideView(root));

    return 0;
}