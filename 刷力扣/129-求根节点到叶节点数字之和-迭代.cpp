/*
- 给你一个二叉树的根节点root，树中每个节点都存放有一个0到9之间的数字。
- 每条从根节点到叶节点的路径都代表一个数字：

例如，从根节点到叶节点的路径1 -> 2 -> 3表示数字 123。
计算从根节点到叶节点生成的 所有数字之和。

叶节点 是指没有子节点的节点。

- 从根节点开始，依次访问元素，将每一个访问到的元素入栈(栈的元素为节点类型)，如果栈顶元素的左孩子为空，则入栈右孩子
- 若都为空，说明到了叶子节点，此时开始处理数值，依照这原则，最终访问完毕所有的叶节点
*/
#include "../headfile/io_for_leetcode.h"
#include "../headfile/TreeNode.h"
#include <stack>
using namespace std;

int sumNumbers(TreeNode* root) {
    stack<TreeNode*> s;
    int result = 0;
    s.push(root);
    int temp_value = root->val;     // 这是一个临时值，随着每一个元素压栈，都要更新，主要是为了获取到叶子节点之间组成的数的大小
    TreeNode* before_top = nullptr; 
    while (!s.empty()) {
        auto temp_node = s.top();   // 临时保存栈顶结点
        while (temp_node->left && temp_node->left != before_top) {
            s.push(temp_node->left);
            temp_node = s.top();    // 更新栈顶节点(名字起得不好，应该叫top_node)
            temp_value = temp_value * 10 + temp_node->val;    // 更新temp_value
        }
        temp_node = s.top();
        if (temp_node->left == nullptr && temp_node->right != before_top && temp_node->right) {
            s.push(temp_node->right);
            temp_node = s.top();    // 更新栈顶节点(名字起得不好，应该叫top_node)
            temp_value = temp_value * 10 + temp_node->val;    // 更新temp_value
        }
        temp_node = s.top();

        if (!temp_node->left && !temp_node->right)  {   // 如果栈顶元素的左右孩子都为空，表明到了叶节点，这里专门处理叶节点
            result += temp_value;   // 更新result

            temp_value /= 10;    // 接下来即将弹出去，因此需要更新temp_value，不要影响对下一个叶子节点的求解
            before_top = s.top();
            s.pop();    // 弹出
        }
        
        if (s.empty())  return result;
        // 如果弹出的结点是栈顶的左结点，那么看看该结点有没有右结点，有，则入栈，更新temp_value
        temp_node = s.top();

        // 如果有过弹出，那么弹出的点要么是栈顶元素的左孩子，要么是右孩子
        if (before_top) {
            if (temp_node->left == before_top) {
                if (temp_node->right) {
                        s.push(temp_node->right);
                        temp_node = s.top();
                        temp_value = temp_value * 10 + temp_node->val;    // 更新temp_value
                }
                // 如果右孩子没有，那这个结点也可以退出了
                else 
                {
                    temp_value /= 10;
                    before_top = s.top();
                    s.pop();    // 同样再次弹出该结点
                }
            }
            else {
                temp_value /= 10;
                before_top = s.top();
                s.pop();
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