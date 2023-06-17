/* 
* 二叉树中的路径被定义为一条节点序列，序列中每对相邻节点之间都存在一条边。
* 同一个节点在一条路径序列中至多出现一次。该路径至少包含一个节点，且不一定经过根节点。

* 路径和是路径中各节点值的总和。

* 给你一个二叉树的根节点root，返回其最大路径和。
*/
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

// 二叉树的节点
struct TreeNode 
{
    int val;            // 结点的值
    TreeNode* left;     // 左结点
    TreeNode* right;    // 右结点
    TreeNode() : val(0), left(nullptr), right(nullptr) {}       // 构造函数1
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}  // 构造函数2
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 建立二叉树的函数，输入仿照leetcode的输入处理
// 按照从上到下，从左到右的顺序给出节点值，如果相应位置没有节点，则以-1作为输入
// 假设给出一个输入：{-10， 9，20，-1，-1，15，7}，代表根节点是-10，接下来根节点左右节点的值分别为9，20，9的左右结点不存在，即为-1
// 20的左右节点值分别为15，7，逻辑上就是这么一个二叉树
TreeNode* buildTree(const vector<int>& nums, int index)
{
    if(index > nums.size() || nums[index] == -1)    return nullptr;

    TreeNode* root = new TreeNode(nums[index]);

    root->left = buildTree(nums, 2 * index + 1);

    root->right = buildTree(nums, 2 * index + 2);

    return root;
}


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

    auto root = buildTree(input, 0);

    cout << maxPathSum(root) << endl;
    
    return 0;
}