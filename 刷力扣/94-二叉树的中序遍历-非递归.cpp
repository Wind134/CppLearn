/*
* 尝试使用迭代写法！
* 处理输入输出可能需要费一番劲头
*/
#include <iostream>
#include <vector>
#include <stack>
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

// 上面成功进行了二叉树的创建，接下来测试遍历(中序)
void inOrderRecursion(TreeNode* root)
{
    if (root == nullptr)    return;
    inOrderRecursion(root->left);
    cout << root->val << " ";
    inOrderRecursion(root->right);
}


void inOrderIter(TreeNode* root)
{
    TreeNode* curr = root;
    stack<TreeNode*> node_stack; // 将结点入栈
    while(curr != nullptr || !node_stack.empty())
    {
        // 如果curr本身就为空，那么while循环不会执行，而是会去执行下面的部分，弹出....输出.....等
        while (curr != nullptr) // 将根节点及其所有左子树的所有左节点都入栈了
        {
            node_stack.push(curr);
            curr = curr->left;
        }

        // 处理栈顶元素，首先可以确认栈顶元素是所有未处理过的节点最左边的那个节点
        curr = node_stack.top();
        node_stack.pop();
        cout << curr->val << " ";

        // 如果该节点还有右子树，则处理右子树
        // 这时候会想，我左子树还未处理啊，但是左子树经过上面的迭代，左节点一定已经被输出了
        curr = curr->right;
    }

}
int main()
{
    TreeNode* root = createBinaryTree();
    cout << "Binary Tree Build!\n" << "Inorder with recursion: ";
    inOrderRecursion(root);
    
    cout << "\nInorder with iteration: ";
    inOrderIter(root);
    return 0;
}