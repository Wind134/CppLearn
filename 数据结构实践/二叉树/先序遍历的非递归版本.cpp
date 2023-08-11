/**
 * 假设结点非空哈，Leetcode 144证明了正确性
 */
#include "../../刷力扣/headfile/io_for_leetcode.h"
#include <stack>
using namespace std;

int main()
{
    input input_binary_tree;
    auto vec = input_binary_tree.input_vector();
    stack<TreeNode*> s;
    auto root = buildTreeWithVec(vec);

    // 下面是先序遍历非递归算法的核心
    s.push(root);          // 先将根节点入栈

    bool tag = true;       // 控制最后一位数没有空格，要不要都行
    cout << "递归版本的先序遍历结果: ";
    preOrderTraversal(root);

    cout << "\n非递归版本的先序遍历结果: ";
    
    while (!s.empty())
    {
        auto node = s.top();
        if (tag) {
            cout << node->val;
            tag = false;
        }
        else    cout << " " << node->val;
        s.pop();    // 推出栈顶元素
        if (node->right)   s.push(node->right);   // 先进后出，先将右边的节点入栈
        if (node->left)   s.push(node->left);     // 再将左边的节点入栈  
    }
    cout << endl;
    return 0;
}