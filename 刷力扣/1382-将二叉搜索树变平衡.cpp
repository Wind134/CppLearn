/*
- 给你一棵二叉搜索树，请你返回一棵平衡后的二叉搜索树，新生成的树应该与原来的树有着相同的节点值。

- 如果有多种结果，请你返回任意一种。

- 这部分的知识点就很好的联系到了之前学二叉树的时候，将一个非平衡树转化为平衡树的方案
    -- 比较直接的一种做法就是先中序遍历原二叉树的结点，将序列存储到一个数组中，再以数组中间结点为根节点，去不断递归构造二叉树

    -- 因此思考的点在于，如何直接基于原二叉树去返回平衡的二叉搜索树
        -- 借助109题递归的思路，我们仿照对链表的处理，去获取树结点的个数，然后不断从中间进行处理
        -- 递归可基于原树进行处理

更新：下面这段分析存在问题，无法确保root->right一定存在啊
- 一些思考：这一类问题，用递归的本质思路是什么呢？
 -- 利用了中序遍历的特性，对于一个中序遍历的结果，我们选择一个中间值mid
 -- 那么mid左边和右边又各自构成了一个中序遍历的结果，那么对于这两个子结果，我们又可以不断分解
 -- 一旦左边的子结果处理完成，我们就可以处理中间这个mid，这就是我们要的根节点，然后根节点的左边指向左边那个子问题组成的树
 -- 根节点的右边指向右边那个子问题组成的树
 -- (高，实在是高)        
*/
#include "../headfile/TreeNode.h"
#include "../headfile/io_for_leetcode.h"
using namespace std;

vector<int> inorder_array;

void build_array(TreeNode* root)    // 通过中序生成数组
{
    if (!root)  return;

    build_array(root->left);
    inorder_array.push_back(root->val);
    build_array(root->right);
}


TreeNode* get_balance_tree(int left, int right)
{
    if (left > right)  return nullptr;

    int mid = (left + right) / 2;
    TreeNode* root = new TreeNode(inorder_array[mid]);

    root->left = get_balance_tree(left, mid - 1);

    root->right = get_balance_tree(mid + 1, right);

    return root;
}

TreeNode* balanceBST(TreeNode* root) {
    if (!root)  return nullptr;
    build_array(root);

    int size = inorder_array.size();
    return get_balance_tree(0, size - 1);
}

int main() {
    input input1382;
    auto vec = input1382.input_vector();

    TreeNode* root = buildTreeWithVec(vec);

    auto result = balanceBST(root);

    preOrderTraversal(result);

    cout << endl;
}