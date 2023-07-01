/* 
* 二叉树中的路径被定义为一条节点序列，序列中每对相邻节点之间都存在一条边。
* 同一个节点在一条路径序列中至多出现一次。该路径至少包含一个节点，且不一定经过根节点。

* 路径和是路径中各节点值的总和。

* 给你一个二叉树的根节点root，返回其最大路径和。
*/
#include <iostream>
#include <memory>
#include <vector>
#include "../headfile/TreeNode.h"
using namespace std;


int getMaxSum(TreeNode* root, int& result)   // 获取结点能获取到的最大值
{
    if (root == nullptr)    return 0;

    int leftSum = max(getMaxSum(root->left, result), 0);

    int rightSum = max(getMaxSum(root->right, result), 0);

    int temp_result = leftSum + rightSum + root->val;

    result = max(result, temp_result);

    return max(leftSum, rightSum) + root->val;

}

int maxPathSum(TreeNode* root) 
{
    int result = -1001;
    getMaxSum(root, result);
    return result;
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

    auto root = buildTreeWithVec(input, 0);

    inOrderTraversal(root);

    cout << "\nThe Maximum Path Sum: " << maxPathSum(root) << endl;
    
    return 0;
}