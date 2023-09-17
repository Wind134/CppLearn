/**
题目：给定两颗树，判断两颗树是否完全一致；
*/
#include "../headfile/io_for_leetcode.h"
using namespace std;

bool isSameTree(TreeNode* p, TreeNode* q) 
{
    if(p == nullptr && q == nullptr)    return true;
    if(p == nullptr && q != nullptr)    return false;
    if(p != nullptr && q == nullptr)    return false;

    auto left = isSameTree(p->left, q->left);
    auto right = isSameTree(p->right, q->right);

    return left && right && q->val == p->val;
}

int main() {
    input input100_1;
    input input100_2;
    auto vec1 = input100_1.input_vector();
    auto vec2 = input100_2.input_vector();
    TreeNode* root1 = buildTreeWithVec(vec1);
    TreeNode* root2 = buildTreeWithVec(vec2);

    cout << boolalpha << isSameTree(root1, root2) << endl;
    return 0;
}