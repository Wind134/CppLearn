/* 
给你一个二叉树的根节点root，判断其是否是一个有效的二叉搜索树。

* 二叉搜索数的定义：
- 二叉搜索树是一种特殊的二叉树，它的每个节点都有一个值，且每个节点的左子树中所有节点的值都小于该节点的值，而右子树中所有节点的值都大于该节点的值。

* 验证的难点在于，根节点的孩子节点的孩子节点是不可控因素，因此我们可以采取中序遍历的方式
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

// 通过链表的形式去创建一个二叉树(通过递归的方式去建立，好办法)
TreeNode* createBinaryTree()
{
    int value;
    cout << "Please input the val of node: (-1 represents null): ";
    cin >> value;
    if (value == -1)    return nullptr;

    TreeNode* new_node = new TreeNode(value);

    cout << "Go on input the left child of " << value << ":" << endl;
    new_node->left = createBinaryTree();

    cout << "Go on input the right child of " << value << ":" << endl;
    new_node->right = createBinaryTree();

    return new_node;
}


// void visitBinaryTree(TreeNode* root)    // 采用先序遍历
// {
//     if (root == nullptr)    return;
//     cout << root->val << " ";
//     visitBinaryTree(root->left);
//     visitBinaryTree(root->right);
// }
vector<int> array;

void visitBinaryTree(TreeNode* root, bool& tag)
{
    if (root == nullptr || !tag)    return;
    visitBinaryTree(root->left, tag);
    array.push_back(root->val);
    if (array.size() > 1 && *(array.end() - 1) <= *(array.end() - 2))  tag = false;
    visitBinaryTree(root->right, tag);
}

bool isValidBST(TreeNode* root)
{
    if (root->left == nullptr && root->right == nullptr)    return true;
    bool result = true;
    visitBinaryTree(root, result);
    return result;
}


int main()
{
    TreeNode* root = createBinaryTree();


    cout << boolalpha << isValidBST(root) << endl;
    
    return 0;
}