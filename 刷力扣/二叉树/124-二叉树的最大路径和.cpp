/*
题目：
- 二叉树中的路径被定义为一条节点序列，序列中每对相邻节点之间都存在一条边。
- 同一个节点在一条路径序列中至多出现一次。该路径至少包含一个节点，且不一定经过根节点。
- 路径和是路径中各节点值的总和。
- 给你一个二叉树的根节点root，返回其最大路径和。

思路：递归
- 不要理解错了题目的意思；
- 只要在一条线上就是一条路径；
- 只需要针对每个结点找到包括这个结点的最大路径和即可；
- 在求取最大路径和的环节中，会存在两种情况：
    -- 包含根节点，左孩子和右孩子的路径，这种路径只有三个结点；
    -- 包含根结点与左孩子或者包含根结点与右孩子的路径；
    -- 上面两种路径是不能同时存在的；

*/
#include "../headfile/io_for_leetcode.h"
using namespace std;

int result = INT_MIN;    
int getMaxSum(TreeNode* root)   // 获取结点能获取到的最大值
{
    if (root == nullptr)    return 0;

    
    // 针对每个结点都去寻找他左右两边的最大路径和，但是不能同时选取左右两个结点
    int leftSum = max(getMaxSum(root->left), 0);    // 选取右结点的最大路径和

    int rightSum = max(getMaxSum(root->right), 0);  // 选取左边结点的最大路径和

    int temp_result = leftSum + rightSum + root->val;

    result = max(result, temp_result);              // 可以看到，这里一直处理的都是result，result才是我们要的结果

    return max(leftSum, rightSum) + root->val;      // 返回只会返回其中一侧的值，求取的结果与返回值分开处理了

}

int maxPathSum(TreeNode* root) 
{
    getMaxSum(root);
    return result;
}

int main()
{
    input input124;
    auto vec = input124.input_vector();
    auto root = buildTreeWithVec(vec, 0);

    maxPathSum(root);

    cout << "The Maximum Path Sum: " << maxPathSum(root) << endl;
    
    return 0;
}