/*
- 给你二叉树的根结点root，请你将它展开为一个单链表：
    - 展开后的单链表应该同样使用TreeNode，其中right子指针指向链表中下一个结点，而左子指针始终为null。
    - 展开后的单链表应该与二叉树先序遍历顺序相同。

之前的方法借用了栈实现，如果基于树本身原地做修改，我们观察树可以发现，本质上对于任何一个根节点，都是对
- 根节点的左子树最右结点与根的右子树的第一个右孩子做连接
- 同时观察每一个没有左孩子或者右孩子的结点，我们都可以利用起这个"虚拟指针"，先将根节点左子树的最右结点与右子树最先的那个结点相连接
- 这样可以通过循环一步一步串接到最后一个结点
*/
#include "../headfile/TreeNode.h"
#include "../headfile/io_for_leetcode.h"
using namespace std;

void flatten(TreeNode* root) {
    TreeNode* curr = root;
    while (curr) {
        if (curr->left) {
            auto next = curr->left;
            auto rightest = next;
            while (rightest->right)     rightest = rightest->right; // 找到最右边的结点

            rightest->right = curr->right;
            curr->left = nullptr;
            curr->right = next;
        }
        curr = curr->right;
    }
}

int main() {
    input input114;

    auto vec = input114.input_vector();

    auto root = buildTreeWithVec(vec);

    flatten(root);

    while (root)
    {
        cout << root->val << " ";
        root = root->right;
    }

    return 0;
}