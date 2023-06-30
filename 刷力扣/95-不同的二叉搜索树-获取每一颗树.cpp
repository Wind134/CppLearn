/* 
* 给你一个整数n，请你生成并返回所有由n个节点组成且节点值从1到n互不相同的不同二叉搜索树。
* 可以按任意顺序返回答案。

* 二叉搜索数的定义：
- 二叉搜索树是一种特殊的二叉树，它的每个节点都有一个值，且每个节点的左子树中所有节点的值都小于该节点的值，而右子树中所有节点的值都大于该节点的值。

* 思路：考虑回溯，我们先假设一个序列[1, n]，假设选根节点的val为i，那么根节点的左子树的节点值全为[1.....i - 1]，右子树的节点值为[i + 1...n]
    - 而左子树又是一个可以去考虑的序列，右子树同样是一个可以去这么考虑的序列，一个大问题分成了两个同样的子问题：
    - 假设两个子问题都生成了根节点的集合，也就是说左序列生成了左子树根节点的集合，右序列生成了右子树根节点的集合；
    - 那么对于i节点而言，从左子树集合中选取一颗左子树，右子树集合中选择一颗右子树，拼接，就实现了一个节点的生成；


* 改进，我们默认的回溯策略，会包含多个重复区间，而这些重复区间其实只需要计算一次，这样就起到了绝佳的剪枝作用    
*/

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode     // 这是一个二叉树结点
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


void visitBinaryTree(TreeNode* root)    // 采用先序遍历
{
    if (root == nullptr)    return;
    cout << root->val << " ";
    visitBinaryTree(root->left);
    visitBinaryTree(root->right);
}

// 根本思想是把遍历过的区间产生根节点的集合放进一个矩阵中，这样就不需要重复计算了
vector<TreeNode*> generateTrees(int start, int end, vector<vector<vector<TreeNode*>>>& map) // 参数处理为一个序列
{
    if(start > end) return {nullptr};

    vector<TreeNode*> allTrees;
    for (int i = start; i <= end; i++)
    {
        if(map[start][i - 1].size() == 0)
        {
            auto leftTrees = generateTrees(start, i - 1, map);
            map[start][i - 1] = leftTrees;
        }

        if(map[i + 1][end].size() == 0)
        {
               
            auto rightTrees = generateTrees(i + 1, end, map);
            map[i + 1][end] = rightTrees;
        }
        

        for(auto& leftTreesRootNode : map[start][i - 1])
        {
            for(auto& rightTreesRootNode : map[i + 1][end])
            {
                
                auto root = new TreeNode(i);
                root->left = leftTreesRootNode;
                root->right = rightTreesRootNode;
                allTrees.emplace_back(root);
            }
        } 
    }
    
    return allTrees;
}


int main()
{
    int input;
    cin >> input;

    // 之所以分配多2的空间，是考虑了第一个和最后一个的两种特殊情况
    vector<vector<vector<TreeNode*>>> interval_map(input + 2, vector<vector<TreeNode*>>(input + 2, vector<TreeNode*>()));
    auto output = generateTrees(1, input, interval_map);
    for(const auto& Tree : output)
    {
        visitBinaryTree(Tree);
        cout << endl;
    }
    return 0;
}