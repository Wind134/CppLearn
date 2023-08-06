/*
题目：
- 给你单链表的头指针head和两个整数left和right，其中left<=right。
- 请你反转从位置left到位置right的链表节点，返回反转后的链表。

思路：注意，是从某两个位置开始翻转；
- 本质上考的还是翻转链表；
*/
#include "../headfile/io_for_leetcode.h"
using namespace std;

ListNode* reverseBetween(ListNode* head, int left, int right)
{
    ListNode* left_node_prev = nullptr;         // left节点，目标是定位到left位置之前的节点
    ListNode* right_node_next = nullptr;        // right节点，他的目标是定位到right之后的那个节点
    ListNode* dummy = new ListNode(0, head);    // 哑指针，指向头结点

    ListNode* move_ptr = dummy;  // 用来遍历节点的变量

    while (right + 1 > 0 || left - 1 > 0) { // 尽管放心移动，题目保证left与right在合理范围内
        if (left == 1)  left_node_prev = move_ptr;
        if (right == 0) right_node_next = move_ptr->next;
        move_ptr = move_ptr->next;
        --left;
        --right;
    }
    // cout << left_node->val << endl;
    // cout << right_node_next->val << endl;

    
    ListNode* prev = left_node_prev;    // 永远指向(子链表)的头结点，即便是哑指针
    ListNode* curr = prev->next;

    // 还要一个可以优化的点，只需要遍历一次，不需要再在子链表区域遍历两次，利用right变量即可；
    while (curr->next != right_node_next)   // 原地翻转，注意，curr是不变的，while循环会一直翻转
    {
        // 处理过程
        auto new_node = curr->next->next;
        curr->next->next = prev->next;  // 指向(子链表)的头结点
        prev->next = curr->next;        // 更新头结点
        curr->next = new_node;          // curr指向翻转前的new_node
    }
    auto new_head = dummy->next;
    delete dummy;
    return new_head;
}

int main()
{
    input input92;
    output output92;
    auto input_vec = input92.input_vector();

    ListNode* list_head = createList(input_vec);


    cout << "Please input the left & right: ";
    int left, right;
    cin >> left >> right;

    ListNode* result = reverseBetween(list_head, left, right);
    outputList(result);

    return 0;
}