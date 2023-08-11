#include "../../刷力扣/headfile/io_for_leetcode.h"
#include <queue>
using namespace std;

int main()
{
    input input_binary_tree;
    auto vec = input_binary_tree.input_vector();
    queue<TreeNode*> q;
    auto root = buildTreeWithVec(vec);

    // 下面是层次遍历算法的核心
    q.push(root);          // 先将根节点入队

    bool tag = true;
    
    while (!q.empty())
    {
        if (q.front()->left)   q.push(q.front()->left);     // 访问节点的左节点存在，入队左节点
        if (q.front()->right)   q.push(q.front()->right);   // 访问节点的右节点存在，入队右节点
        if (tag) {
            cout << q.front()->val;
            tag = false;
        }
        else    cout << " " << q.front()->val;                   // 输出访问节点
        q.pop();    // 访问过的元素，出队    
    }
    cout << endl;
    return 0;
}