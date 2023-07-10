/*
给你二叉树的根节点root和一个整数目标和targetSum，找出所有从根节点到叶子节点路径总和等于给定目标和的路径。
*/
#include "../headfile/TreeNode.h"
#include "../headfile/io_for_leetcode.h"
using namespace std;

vector<vector<int>> result;
vector<int> vec_of_result;

void backtrace(TreeNode* root, int target)
{
    //if (target < 0) return; // 不必再递归下去了(如果是正数)
    if (root && !root->left && !root->right)    // 到了叶结点，到底了
    {
        if (root->val == target)
        {
            vec_of_result.push_back(root->val);
            result.push_back(vec_of_result);
            vec_of_result.pop_back();
        }
        return;
    }

    if (root->left)
    {
        vec_of_result.push_back(root->val);
        backtrace(root->left, target - root->val);
        vec_of_result.pop_back();
    }

    if (root->right)
    {
        vec_of_result.push_back(root->val);
        backtrace(root->right, target - root->val);
        vec_of_result.pop_back();
    }
}

vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
{
    if (!root)  return result;

    backtrace(root, targetSum);

    return result;
}

int main()
{
    input input113;
    auto vec = input113.input_vector();

    auto root = buildTreeWithVec(vec);

    cout << "Please input the Target Value: ";

    int target;

    cin >> target;

    output output113;
    
    output113.output_matrix(pathSum(root, target));

    return 0;
}