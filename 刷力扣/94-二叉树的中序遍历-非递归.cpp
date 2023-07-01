/*
* 尝试使用迭代写法！
* 处理输入输出可能需要费一番劲头
*/
#include <iostream>
#include <vector>
#include <stack>
#include "../headfile/TreeNode.h"
using namespace std;


void inOrderIter(TreeNode* root)
{
    TreeNode* curr = root;
    stack<TreeNode*> node_stack; // 将结点入栈
    while(curr != nullptr || !node_stack.empty())
    {
        // 如果curr本身就为空，那么while循环不会执行，而是会去执行下面的部分，弹出....输出.....等
        while (curr != nullptr) // 将根节点及其所有左子树的所有左节点都入栈了
        {
            node_stack.push(curr);
            curr = curr->left;
        }

        // 处理栈顶元素，首先可以确认栈顶元素是所有未处理过的节点最左边的那个节点
        curr = node_stack.top();
        node_stack.pop();
        cout << curr->val << " ";

        // 如果该节点还有右子树，则处理右子树
        // 这时候会想，我左子树还未处理啊，但是左子树经过上面的迭代，左节点一定已经被输出了
        curr = curr->right;
    }

}
int main()
{
    vector<int> input;

    int input_data;

    while (cin >> input_data)
    {
        input.push_back(input_data);
        if(cin.get() == '\n')   break;
    }

    TreeNode* root = buildTreeWithVec(input, 0);
    cout << "Binary Tree Build!\n" << "Inorder with recursion: ";
    inOrderTraversal(root);
    
    cout << "\nInorder with iteration: ";
    inOrderIter(root);
    return 0;
}