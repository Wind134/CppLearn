/**
题目：
- 从底向上的层序遍历；

思路：
- 逆向，然后翻转；
*/
#include "../headfile/io_for_leetcode.h"
#include <algorithm>
#include <queue>

using namespace std;


vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> result;
    if (!root)  return result;

    queue<TreeNode*> treeNode_que;

    treeNode_que.push(root);

    while (!treeNode_que.empty())
    {
        vector<int> vec_of_result;
        int size = treeNode_que.size(); // 队列的长

        for (int i = 0; i < size; i++)
        {
            vec_of_result.push_back(treeNode_que.front()->val);

            if (treeNode_que.front()->left) treeNode_que.push(treeNode_que.front()->left);
            if (treeNode_que.front()->right) treeNode_que.push(treeNode_que.front()->right);

            treeNode_que.pop();
        }

        result.emplace_back(vec_of_result);
    }

    reverse(result.begin(), result.end());

    return result;

}

int main()
{
    input input107;
    auto input_vec = input107.input_vector();
    
    TreeNode* root = buildTreeWithVec(input_vec);  // 默认参数是0

    auto result = levelOrderBottom(root);

    output output107;
    output107.output_matrix(result);
    return 0;
}