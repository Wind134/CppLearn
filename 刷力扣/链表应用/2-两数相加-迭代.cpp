/*
题目：
- 给你两个非空的链表，表示两个非负的整数。它们每位数字都是按照逆序的方式存储的，并且每个节点只能存储一位数字。
- 请你将两个数相加，并以相同形式返回一个表示和的链表。
- 你可以假设除了数字0之外，这两个数都不会以0开头。

思路：这是一道链表题，从头结点开始遍历即可，遇到进位的需要标记一下；
- 不需要另外建立一张表，直接基于原链表修改值就好，默认基于l1吧

- 基于原链表的写法，需要考虑长度问题，直接新建链表吧，这样也可以不破坏原链表的结构
*/
#include "../headfile/io_for_leetcode.h"
using namespace std;


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
    // 条件给定链表长至少为1，不需要考虑空表的情况
    ListNode* res_root = new ListNode();    // 头结点
    bool tag = false;   // 判断是否需要进位
    ListNode* new_node = res_root;          // 该节点是后续需要顺着结点移动
    while (l1 || l2) {
        int num1 = l1 ? l1->val : 0;
        int num2 = l2 ? l2->val : 0;

        if (num1 + num2 + tag < 10) {   // 这个处理方式很棒，让tag参与运算
            int sum = num1 + num2 + tag;
            new_node->val = sum;
            tag = false;
        } else {
            int sum = num1 + num2 + tag - 10;
            new_node->val = sum;
            tag = true;
        }


        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;

        if (l1 || l2) {
            new_node->next = new ListNode();
            new_node = new_node->next;
        }
        
        
    }
    if (tag)    new_node->next = new ListNode(1);

    return res_root;
}
        
int main()
{
    input input2_1, input2_2;
    auto vec1 = input2_1.input_vector();
    auto vec2 = input2_2.input_vector();
    ListNode* lst1 = createList(vec1);
    ListNode* lst2 = createList(vec2);

    ListNode* new_list = addTwoNumbers(lst1, lst2);
    
    outputList(new_list);

    return 0;
}        