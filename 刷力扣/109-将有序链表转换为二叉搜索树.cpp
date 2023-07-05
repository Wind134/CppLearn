/*
- 将有序链表转换为二叉搜索树，要求这颗树高度平衡

- 对比数组，由于不能随机访问，因此需要想想其他策略
    -- 转化成数组进行处理......
    -- 利用快慢指针找到中间节点(这是在链表中学到的一点巧妙办法)
    -- 但是更巧妙的还是虚拟根节点结合递归的做法，为什么会用到虚拟根节点呢？这要结合中序遍历的特点：[左 根 右]
    -- 链表中的序列恰好就是一个中序遍历的结果
*/
#include "../headfile/io_for_leetcode.h"
#include "../headfile/TreeNode.h"
#include "../headfile/ListNode.h"
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

    root->left = get_balance_tree(head, left, mid - 1);

    root->val = head->val;  // 赋值的这一步，必须等到上述函数递归完成才会执行，而这一步的第一次执行，应该是赋值给了最左边的那个点

    head = head->next;      // 每次赋值给了一个节点，就需要更新到下一个节点，而下一个节点，显然是为递归最深处的那个结点的右结点准备的

    // 在处理右边节点之前，我们需要将每一个虚拟根节点进行赋值，这一点很重要！
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