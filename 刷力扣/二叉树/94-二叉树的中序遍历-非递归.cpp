/*
题目：采用迭代的做法对二叉树进行中序遍历；

思路：借用一个栈；
- 从根节点开始，如果根节点有右孩子，将右孩子节点先入栈，之后将该节点入栈；
- 然后从根节点开始不断找左节点，如果找到的左节点有右孩子，同样，将这个右孩子入栈，再将本节点入栈
- 依次类推，直到找到最左边的根节点，同样，如果这个最左边的根节点有右孩子，也要入栈，之后输出该节点的值
- 经过上面的那一步，下一个要处理的节点就是栈顶元素的节点，栈顶元素的节点的处理方式：
- 先从栈顶弹出这个节点，然后针对这个弹出的节点，重复上面的步骤，有右孩子，入栈，接着找左孩子....
- 栈中每个元素都是这么处理，直到最后栈空
*/
#include "../headfile/io_for_leetcode.h"
#include <stack>
using namespace std;


void inOrderIter(TreeNode* root)
{
    if (!root)  return; 
    stack<TreeNode*> node_stack; // 将结点入栈
    
    // 先将根节点入栈
    node_stack.push(root);
    auto curr = node_stack.top();   // 当前要处理的节点

    while(!node_stack.empty())
    {
        while (curr->left)  {
            curr = curr->left;
            node_stack.push(curr);  // 将左节点入栈
        }
        // 栈顶元素不一定总是curr，下面针对栈顶元素做输出
        // 不一定总是curr的原因在于while循环可能不会执行
        // 下面的if也可能不会执行
        auto top_node = node_stack.top();    
        
        cout << top_node->val << " ";   // 经过上面的循环处理，除最左边之外所有的左节点都入栈了，那这个节点可以输出了
        // 输出之后，弹出节点
        node_stack.pop();

        if (top_node->right) {
            node_stack.push(top_node->right);
            curr = top_node->right;    // 更新要处理的curr节点，它又会像上面一样，去找最左边的结点
        }
    }
}
int main()
{
    input input94;
    auto input_vec = input94.input_vector();

    TreeNode* root = buildTreeWithVec(input_vec);

    cout << "Binary Tree Build!\n" << "Inorder with recursion: ";
    inOrderTraversal(root);
    
    cout << "\nInorder with iteration: ";
    inOrderIter(root);
    return 0;
}