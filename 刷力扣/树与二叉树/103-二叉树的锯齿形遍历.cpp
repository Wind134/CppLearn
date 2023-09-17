/*
题目：
- 给你二叉树的根节点root，返回其节点值的层序遍历。(即逐层地，从左到右访问所有节点)
- 返回的类型是一个二维数组

与101层序遍历的区别的区别：
- 返回节点值的锯齿形层序遍历。(即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行)

思路：
- 层序遍历的思路是，将即将访问的节点的左孩子与右孩子分别入队，当节点访问之后，接着访问节点的左孩子，对于即将访问的左孩子节点
- 同样遵循上述的思路
- 但是由于需要返回一个二维数组，其中二维数组中的每一个数组是某一层的节点元素(因此需要特殊处理一下)
*/
#include <queue>
#include <algorithm>
#include "../headfile/io_for_leetcode.h"
using namespace std;

vector<vector<int>> levelOrder(TreeNode* root)
{
    vector<vector<int>> result_output;
    if (!root)  return result_output;    
    queue<TreeNode* > node_queue;   // 元素类型是树的结点类型
    node_queue.push(root);      // 先加入根节点
    bool tag = false;
    while (!node_queue.empty()) // 队列不空，则循环执行以下，直到结束
    {
        int size = node_queue.size();
        vector<int> vec_of_result;
        for (int i = 0; i < size; i++)
        {
            auto* node = node_queue.front();
            vec_of_result.emplace_back(node->val);
            if (node->left) node_queue.push(node->left);
            if (node->right) node_queue.push(node->right);
            node_queue.pop();   // 弹出元素
        }
        if (tag)
        {
            reverse(vec_of_result.begin(), vec_of_result.end());
            tag = false;
        }
        else    tag = true;

        result_output.emplace_back(vec_of_result);
    }
    return result_output;
}

int main()
{
    input input103;
    auto input_vec = input103.input_vector();
    
    TreeNode* root = buildTreeWithVec(input_vec);  // 默认参数是0

    auto result = levelOrder(root);

    output output103;
    output103.output_matrix(result);
    return 0;
}