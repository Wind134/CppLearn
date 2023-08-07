/*
题目：
- 将有序链表转换为二叉搜索树，要求这颗树高度平衡

思路：
- 对比数组，由于不能随机访问，因此需要想想其他策略：
    -- 主要的思路还是递归，假设给定了一个链表的区间[left, right]；
    -- 显然，通过mid一分为二：[left, mid - 1]和mid和[mid + 1, right]；
    -- 我们可以用一个递归针对左边的子树进行求取，求左边的子树，传递的头结点一定是这个大区间的头结点
    -- 我们假设左边的这个求了出来，此时将根节点的left指向那颗子树，根节点我们暂时不知道它的值；
    -- 那我们从思路上先去求取[mid + 1, right]的子树，显然求这部分子树，需要更新传进去的头结点；
    -- 这部分的头结点是什么呢？这是递归中体现出的最巧妙的策略了，就是在上面求出左子树之后，只要给head传
    -- 引用实参，head会在每一层递归中不断更新，我们只需要保证一次递归中更新一次
    -- 比如1 2 3 4 5，求[1 2]和[4 5]分别对应的子树，求[1 2]的时候，求[1]和[](空)的子树
    -- 求[1]的时候，我们把head赋给root之后，更新head，那么head就给了2，更好2是[1]和[]的根节点
    -- 所以只要在处理完左子树之后，head更新一次，那么等左区间处理器完之后，给到root的head节点正好就是我们要用的root节点；
*/
#include "../headfile/io_for_leetcode.h"
using namespace std;

// 获取链表长度
int get_length(ListNode* head)
{
    int count = 0;
    while (head)
    {
        count++;
        head = head->next;
    }
    return count;
}

TreeNode* get_balance_tree(ListNode*& head, int left, int right)    // head要改变，因此指针需要引用
{
    if (left > right)   return nullptr;

    int mid = (left + right) / 2;

    TreeNode* root = new TreeNode();    // 分配一个虚拟根节点

    root->left = get_balance_tree(head, left, mid - 1); // 先对mid左边的递归

    root->val = head->val;  // 赋值的这一步，必须等到上述函数递归完成才会执行，而这一步的第一次执行，应该是赋值给了最左边的那个点

    head = head->next;      // 每次赋值给了一个节点，就需要更新到下一个节点，而下一个节点，显然是为递归最深处的那个结点的右结点准备的

    // 在处理右边节点之前，我们需要将每一个虚拟根节点进行赋值，这一点很重要！
    // head作为下一个递归的开头
    root->right = get_balance_tree(head, mid + 1, right);

    return root;
}

TreeNode* sortedListToBST(ListNode* head) {
    int length = get_length(head);

    return get_balance_tree(head, 0, length - 1);
}

int main()
{
    input input109;
    auto input_array = input109.input_vector();

    auto list_head = createList(input_array);

    auto result = sortedListToBST(list_head);

    preOrderTraversal(result);
    cout << endl;
}