/**
 * 假设结点非空，Leetcode 94证明了正确性；
 * 
 * 思路:
 * 针对某个节点，寻找该节点的左侧节点，如果该左侧节点存在，更新要寻找的左侧节点；
 * 如果该左侧结点不存在，输出该节点，同时将该节点的右孩子入栈；
 * 去处理栈中的结点，针对栈顶结点，同上按照上面的步骤来进行，直到左侧节点不存在；
 * 每一次迭代到左侧结点不存在都是一个循环，循环一直在栈中进行，因此我们在初始时先将根节点入栈；
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

    cout << "递归版本的中序遍历结果: ";
    inOrderTraversal(root);
    cout << "\n非递归版本的中序遍历结果: ";
    
    bool tag = true;       // 控制最后一位数没有空格，要不要都行

    // 下面是中序遍历非递归算法的核心，对栈的初始处理
    s.push(root);

    auto curr = s.top();
    
    while (!s.empty())  // 只要栈不空，则针对栈顶元素同样按照上述步骤处理
    {
        // 下面这个循环将每一个不为空的左节点都入栈
        while (curr->left) {
            curr = curr->left;  
            s.push(curr);
        }

        auto top_node = s.top();    // 栈顶元素不一定总是curr，下面针对栈顶元素做输出

        if (tag) {
            cout << top_node->val;
            tag = false;
        }
        else    cout << " " << top_node->val;

        s.pop();    // 弹出该结点
        if (top_node->right) {  // 如果右节点存在，则更新curr，更新之后接着找最左边的结点
            s.push(top_node->right);
            curr = top_node->right;    // 如果这个结点右孩子存在，则将右孩子入栈
        }
    }
    cout << endl;
    return 0;
}