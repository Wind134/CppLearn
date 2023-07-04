/*
给你二叉搜索树的根节点root，该树中的恰好两个节点的值被错误地交换。请在不改变其结构的情况下，恢复这棵树。

要想一次遍历实现我们的目的，我们的思路是，可以在遍历的过程中，将产生了逆序的节点保存下来，同样是面临了两种情况：
- 产生两个逆序的情况：将第一个逆序中的第一个值与第二个逆序中第二个值进行交换
- 产生一个逆序，将逆序中的两个值进行交换

最后交换两个节点值即可，其实也不难，主要的难点在于，怎么获取到这两个节点，假设我预定义两个节点准备存储需要交换的两个节点：
由于是一次遍历，我不知道整个序列会有几个逆序，那我应该采取什么样的策略来解决这个问题呢？
- 我在遇到第一个逆序时，不管怎样，将第一个节点赋值为该逆序中第的前一个结点，将第二个节点赋值为该逆序中第的第二个结点
- 如果真的只有一个逆序，这个策略可以完美生效
- 如果遇到第二个逆序，将第二个节点进行更改，更改为该逆序中的第二个节点
这样是不是就解决了问题？

还有一个优化点：不需要等到全部遍历完成
*/
#include <iostream>
#include <vector>
#include <utility>
#include "../headfile/TreeNode.h"
using namespace std;

TreeNode* last_node = nullptr;
TreeNode* swap_node1 = nullptr;
TreeNode* swap_node2 = nullptr;


void getBinaryTreeInfo(TreeNode* root)    // 采用中序遍历
{
    if (root == nullptr)    return;
    getBinaryTreeInfo(root->left);
    if (last_node == nullptr)   last_node = root;
    else
    {
        if(last_node->val < root->val)  last_node = root;   // 正常更新处理
        else
        {
            if (swap_node1 == nullptr)
            {
                swap_node1 = last_node; // 更新了swap_node1之后就不能再动它了
            }
              
            if(swap_node2 != nullptr)
            {
                swap_node2 = root;  // swap_node2无论如何都需要更新
                return; // 这样处理效率更高，后续不需要再递归了
            }
            swap_node2 = root;
            last_node = root;
        }
    }
    getBinaryTreeInfo(root->right);
}



void recoverTree(TreeNode* root)
{
    getBinaryTreeInfo(root);
    swap(swap_node1->val, swap_node2->val);
}

int main()
{
    TreeNode* root = createBinaryTree();

    cout << "Original inorder Sequence:";

    inOrderTraversal(root);

    recoverTree(root);

    cout << endl;

    cout << "After recover inorder Sequence:";
    inOrderTraversal(root);
    
    cout << endl;
    return 0;
}