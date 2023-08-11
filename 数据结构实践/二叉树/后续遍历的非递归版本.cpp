/**
 * 假设结点非空，Leetcode 145证明了正确性；
 * 
 * 思路:
 * 先序遍历是根左右，后续遍历是左右根，在先序遍历中，我们在栈中处理左右孩子的方式是：
 * 先输出根节点，再将右孩子入栈，再入栈左孩子，如果我们调整一下入栈的顺序，可以使得结点形式变为根右左；
 * 假设针对上面的顺序，我们让这几个结点依次再入一个栈，根->右->左，那出栈顺序岂不是左右根......；
 * 每一组结点都可以通过这种方式入另一个栈，最终问题解决；
 */
#include "../../刷力扣/headfile/io_for_leetcode.h"
#include <stack>
using namespace std;

int main()
{
    input input_binary_tree;
    auto vec = input_binary_tree.input_vector();
    
    stack<TreeNode*> s_process;
    stack<TreeNode*> s_output;

    auto root = buildTreeWithVec(vec);

    cout << "递归版本的后序遍历结果: ";
    postOrderTraversal(root);
    cout << "\n非递归版本的后序遍历结果: ";
    
    bool tag = true;       // 控制最后一位数没有空格，要不要都行

    // 下面是后序遍历非递归算法的核心，对栈的初始处理
    s_process.push(root);
    
    while (!s_process.empty())
    {
        auto top_node = s_process.top();
        s_output.push(top_node);

        s_process.pop();    // 推出栈顶元素
        if (top_node->left)   s_process.push(top_node->left);   // 先将左边的节点入栈
        if (top_node->right)   s_process.push(top_node->right);     // 再将右边的节点入栈  
    }

    while (!s_output.empty()) {
        if (tag) {
            cout << s_output.top()->val;
            tag = false;
        } else cout << " " << s_output.top()->val;
        s_output.pop();
    }
    cout << endl;
    return 0;
}