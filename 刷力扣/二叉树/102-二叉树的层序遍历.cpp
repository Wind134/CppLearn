/*
题目：
- 给你二叉树的根节点root，返回其节点值的层序遍历。(即逐层地，从左到右访问所有节点)
- 返回的类型是一个二维数组

思路：
- 层序遍历的思路是，将即将访问的节点的左孩子与右孩子分别入队；
- 当节点访问之后，接着访问节点的左孩子，对于即将访问的孩子节点同样遵循上述的思路；
- 但是由于需要返回一个二维数组，其中二维数组中的每一个数组是某一层的节点元素(因此需要特殊处理一下)
*/
#include <queue>
#include "../headfile/io_for_leetcode.h"
using namespace std;

vector<vector<int>> levelOrder(TreeNode* root)
{
    vector<vector<int>> res;
    if (!root)  return res;    
    queue<TreeNode* > node_queue;   // 元素类型是树的结点类型
    node_queue.push(root);      // 先加入根节点
    while (!node_queue.empty()) // 队列不空，则循环执行以下，直到结束
    {
        int size = node_queue.size();
        vector<int> vec_of_result;
        for (int i = 0; i < size; i++)
        {
            auto node = node_queue.front();
            vec_of_result.emplace_back(node->val);
            if (node->left) node_queue.push(node->left);
            if (node->right) node_queue.push(node->right);
            node_queue.pop();   // 弹出元素
        }
        res.emplace_back(vec_of_result);
    }
    return res;
}

int main()
{
    input input102;
    auto input_vec = input102.input_vector();
    
    TreeNode* root = buildTreeWithVec(input_vec);  // 默认参数是0

    auto result = levelOrder(root);

    output output102;
    output102.output_matrix(result);
    return 0;
}