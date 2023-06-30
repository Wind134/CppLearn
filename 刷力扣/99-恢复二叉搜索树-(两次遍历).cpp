/*
给你二叉搜索树的根节点root，该树中的恰好两个节点的值被错误地交换。请在不改变其结构的情况下，恢复这棵树。

二叉搜索树经过中序遍历之后，一个严格递增的序列；

比如说正常来说，二叉搜索树得到的序列是：[1 2 3 4 5 6 7]，假设2和6换了一个位置[1 6 3 4 5 2 7]：
- 这种情况下，有两个位置产生了逆序[6 3]、[5 2]，假设起始位置分别为i、j；
- 如果是2和3交换了一个位置，则只产生一个逆序[3 2];
也就是说，交换后的就只会面临两种情况，产生一个逆序，或者两个逆序；
- 在产生两个逆序的情况下，将第一个逆序位置i与第二个逆序位置j + 1的进行调换即可
- 产生一个逆序的情况下，将这个逆序的两个元素调换即可
*/

#include <iostream>
#include <vector>
#include <utility>
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

void visitBinaryTree(TreeNode* root)    // 采用中序遍历，main函数测试之用
{
    if (root == nullptr)    return;
    visitBinaryTree(root->left);
    cout << root->val << " ";
    visitBinaryTree(root->right);
}

void getBinaryTreeInfo(TreeNode* root, vector<int>& vec)    // 采用中序遍历
{
    if (root == nullptr)    return;
    getBinaryTreeInfo(root->left, vec);
    vec.push_back(root->val);
    getBinaryTreeInfo(root->right, vec);
}


// 实现真正的恢复
void recoverBinaryTree(TreeNode* root, const vector<pair<int, int>>& seq, const vector<int>& vec)    // 采用中序遍历
{
    if (root == nullptr)    return;
    recoverBinaryTree(root->left, seq, vec);
    if (seq.size() == 2)
    {
        if (root->val == vec[seq[0].first]) root->val = vec[seq[1].second];
        else
        {
            if (root->val == vec[seq[1].second]) root->val = vec[seq[0].first];
        }
    }

    if (seq.size() == 1)
    {
        if (root->val == vec[seq[0].first]) root->val = vec[seq[0].second];
        else
        {
            if (root->val == vec[seq[0].second]) root->val = vec[seq[0].first];
        }
    }

    recoverBinaryTree(root->right, seq, vec);
}


void recoverTree(TreeNode* root)
{
    vector<int> vec;
    getBinaryTreeInfo(root, vec);
    int size = vec.size();
    vector<pair<int, int>> reverse_seq;
    for (int i = 1; i < size; i++)
    {
        if (vec[i] < vec[i - 1])    reverse_seq.push_back({i - 1, i});
    }
    recoverBinaryTree(root, reverse_seq, vec);
}

int main()
{
    TreeNode* root = createBinaryTree();

    recoverTree(root);

    visitBinaryTree(root);
    
    return 0;
}