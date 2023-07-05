/* 刷题每次都要重写或者复制一些创建树，遍历树，这种重复操作可以包含在一个头文件中 */
#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>
#include <vector>

// #ifndef MIN_MAX
// const int& MIN_INT = -2147483648;
// const int& MAX_INT = 2147483647;
// #endif

// 这是一个二叉树结点的类定义(结构体)
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 树的创建方式一
TreeNode* createBinaryTree()
{
    int value;
    std::cout << "Please input the val of node: (-1 represents null): ";
    std::cin >> value;
    if (value == -1)    return nullptr;

    TreeNode* new_node = new TreeNode(value);

    std::cout << "Go on input the left child of " << value << ":" << std::endl;
    new_node->left = createBinaryTree();

    std::cout << "Go on input the right child of " << value << ":" << std::endl;
    new_node->right = createBinaryTree();

    return new_node;
}

// 树的创建方式二，通过二叉树的数组特性(就Leetcode刷题而言，这个方式其实省输入时间)
// 建立二叉树的函数，输入仿照leetcode的输入处理
// 按照从上到下，从左到右的顺序给出节点值，如果相应位置没有节点，则以-1作为输入
// 假设给出一个输入：{-10， 9，20，-1，-1，15，7}，代表根节点是-10，接下来根节点左右节点的值分别为9，20，9的左右结点不存在，即为-1
// 20的左右节点值分别为15，7，逻辑上就是这么一个二叉树
TreeNode* buildTreeWithVec(const std::vector<int>& nums, int index = 0) // 给一个默认参数不影响什么吧，这是默认的起始位置
{
    if(index > nums.size() - 1 || nums[index] == -1)    return nullptr; // -1代表该节点不存在(注意权值为-1的情况即可)

    TreeNode* root = new TreeNode(nums[index]);

    root->left = buildTreeWithVec(nums, 2 * index + 1);

    root->right = buildTreeWithVec(nums, 2 * index + 2);

    return root;
}

bool first_visit_pre = true;
// 树的先序遍历
void preOrderTraversal(TreeNode* root)
{
    if (root == nullptr)    return;
    if (first_visit_pre)
    {
        std::cout << root->val;
        first_visit_pre = false;
    }
    else    std::cout << " " << root->val;
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// 定义一个带两个参数的重载函数
void preOrderTraversal(TreeNode* root, bool& first_visit)
{
    if (root == nullptr)    return;
    if (first_visit)
    {
        std::cout << root->val;
        first_visit = false;
    }
    else    std::cout << " " << root->val;
    preOrderTraversal(root->left, first_visit);
    preOrderTraversal(root->right, first_visit);
}


// 树的中序遍历
bool first_visit_in = true;
void inOrderTraversal(TreeNode* root)
{
    if (root == nullptr)    return;
    inOrderTraversal(root->left);
    if (first_visit_in)
    {
        std::cout << root->val;
        first_visit_in = false;
    }
    else    std::cout << " " << root->val;
    inOrderTraversal(root->right);
}

bool first_visit_post = true;
// 树的后序遍历
void postOrderTraversal(TreeNode* root)
{
    if (root == nullptr)    return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    if (first_visit_post)
    {
        std::cout << root->val;
        first_visit_post = false;
    }
    else    std::cout << " " << root->val;
}

#endif