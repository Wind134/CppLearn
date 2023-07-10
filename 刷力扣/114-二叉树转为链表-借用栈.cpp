/*

- 给你二叉树的根结点root，请你将它展开为一个单链表：
    - 展开后的单链表应该同样使用TreeNode，其中right子指针指向链表中下一个结点，而左子指针始终为null。
    - 展开后的单链表应该与二叉树先序遍历顺序相同。
*/
#include "../headfile/TreeNode.h"
#include "../headfile/io_for_leetcode.h"
#include <stack>
using namespace std;

stack<TreeNode*> TreeNodeInfo;
void flatten_with_stack(TreeNode* root) {
    if (!root)  return;

    TreeNodeInfo.push(root);

    flatten_with_stack(root->left);

    flatten_with_stack(root->right);
}

int main() {
    input input114;

    auto vec = input114.input_vector();

    auto root = buildTreeWithVec(vec);

    flatten_with_stack(root);

    auto last_node = TreeNodeInfo.top();

    last_node->left = nullptr;
    last_node->right = nullptr;

    TreeNodeInfo.pop();

    while (!TreeNodeInfo.empty())
    {
        TreeNodeInfo.top()->left = nullptr;
        TreeNodeInfo.top()->right = last_node;
        last_node = TreeNodeInfo.top();
        TreeNodeInfo.pop();
    }

    root = last_node;
    
    while (root)
    {
        cout << root->val << " ";
        root = root->right;
    }

    return 0;
}