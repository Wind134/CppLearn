/* 这个题简单，就不写主程序了 */

struct TreeNode     // 这是一个二叉树结点
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
TreeNode* p,q;
bool isSameTree(TreeNode* p, TreeNode* q) 
{
    if(p == nullptr && q == nullptr)    return true;
    if(p == nullptr && q != nullptr)    return false;
    if(p != nullptr && q == nullptr)    return false;

    auto left = isSameTree(p->left, q->left);
    auto right = isSameTree(p->right, q->right);

    return left && right && q->val == p->val;
}