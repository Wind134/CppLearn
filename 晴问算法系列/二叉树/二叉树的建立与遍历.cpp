/* 我都采用了C++11的智能指针版 */

#include <iostream>
#include <memory>
#include <vector>
using namespace std;

struct TreeNode 
{
    int val;            // 结点的值
    shared_ptr<TreeNode> left;     // 左结点
    shared_ptr<TreeNode> right;    // 右结点
    TreeNode() : val(0), left(nullptr), right(nullptr) {}       // 构造函数1
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}  // 构造函数2
    TreeNode(int x, shared_ptr<TreeNode> left, shared_ptr<TreeNode> right) : val(x), left(left), right(right) {}
};

// 下面这种建立方法保证根节点存在(一个错误的建立方式)
// void buildTree(TreeNode* root, const vector<int>& nums, int index)
// {
//     if(index > nums.size() || nums[index] == -1)    return;

//     root->val = nums[index];

//     buildTree(root->left, nums, 2 * index + 1); // root->left是空指针，大哥！
//     buildTree(root->right, nums, 2 * index + 2);
// }

shared_ptr<TreeNode> buildTree(const vector<int>& nums, int index)
{
    if(index > nums.size() || nums[index] == -1)    return nullptr;

    shared_ptr<TreeNode> root = make_shared<TreeNode>(nums[index]);

    root->left = buildTree(nums, 2 * index + 1);

    root->right = buildTree(nums, 2 * index + 2);

    return root;
}

void traverseInOrder(shared_ptr<TreeNode> root)
{
    if (root == nullptr)    return;

    traverseInOrder(root->left);
    cout << root->val << endl;
    traverseInOrder(root->right);
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

    traverseInOrder(root);

    cout << "Traverse Finished!" << endl;

    return 0;
    
}