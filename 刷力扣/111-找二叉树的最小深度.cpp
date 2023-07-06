/* 
- 给定一个二叉树，找出其最小深度。

注：最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
*/
#include "../headfile/TreeNode.h"
#include "../headfile/io_for_leetcode.h"
#include <algorithm>
using namespace std;

int minDepth(TreeNode* root)
{
    if (!root)  return 100000;    
    if (root && !root->left && !root->right)    // 如果结点本身不空，但左右子树都是空，说明到叶节点了
        return  1;

    return min(minDepth(root->left), minDepth(root->right)) + 1;
}

int main()
{
    input input111;
    
    vector<int> vec = input111.input_vector();

    TreeNode* root = buildTreeWithVec(vec);

    cout << minDepth(root) << endl;

    return 0;
}