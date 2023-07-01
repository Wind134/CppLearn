/*
* 给你单链表的头指针head和两个整数left和right，其中left<=right。
* 请你反转从位置left到位置right的链表节点，返回反转后的链表。

* 思路：注意，是从某两个位置开始翻转
*/
#include <iostream>
#include <memory>
#include <vector>
#include "../headfile/ListNode.h"
using namespace std;

ListNode* reverseBetween(ListNode* head, int left, int right)
{
    ListNode* prev = nullptr;   // 定义一个前驱节点，他的目标是定位到left之前的那个节点
    ListNode* next = nullptr;   // 定义一个后继节点，他的目标是定位到right之后的那个节点

    ListNode* move_ptr = head;  // 用来遍历节点的变量
    int count = 1;  // 用来指明节点数，初始值为1，题目已经给定条件，节点数至少为1

    while (move_ptr != nullptr && count < left - 1)    // 因为我们要前一个结点
    {
        move_ptr = move_ptr->next;
        count++;
    }

    if (left != 1)  prev = move_ptr;    // 只不是从头节点开始翻转，prev就能这么处理

    while (move_ptr != nullptr && count != right)    // 因为我们要前一个结点
    {
        move_ptr = move_ptr->next;
        count++;
    }
    next = move_ptr->next;  // 这里可能为空，指向的是right位置的下一个结点

    // 接下来的任务就是翻转链表了，先将要翻转的单独处理一下
    move_ptr->next = nullptr;   // 子链表的最后一个节点指向空

    ListNode* reverse_head = nullptr;
    if (left != 1)  reverse_head = prev->next;    // 要反转的子链表已拿出来了
    else reverse_head = head; 

    // 最后单独对子链表进行处理
    ListNode* reverse_prev = reverse_head;  // 遍历的当前结点
    ListNode* reverse_curr = reverse_prev->next;  // 遍历的下一个结点
    ListNode* new_head = reverse_head;      //  未经过翻转处理的链表的头结点，后续该结点需要随时更新

    while (reverse_curr != nullptr)
    {
        // 处理过程
        reverse_prev->next = reverse_curr->next;
        reverse_curr->next = new_head;      // 将curr节点指向上一个更新的头结点
        new_head = reverse_curr;
        
        reverse_curr = reverse_prev->next;
    }

    // 经过上面的处理，子链表已翻转
    if (prev != nullptr)    prev->next = new_head;
    else    head = new_head;
    
    reverse_prev->next = next;
    
    return head;

}



int main()
{
    vector<int> input;  // 根据输入的数组创建链表

    int input_data;

    while (cin >> input_data)
    {
        input.push_back(input_data);
        if(cin.get() == '\n')   break;
    }

    ListNode* list_head = createList(input);    // 拷贝赋值，意味着对list_head的修改不会影响，但如果对它指向的内容进行修改就有事了
    ListNode* save = list_head;

    while(list_head != nullptr)
    {
        cout << list_head->val << " ";
        list_head = list_head->next;
    }

    cout << "\nSuccess Established!" << endl;

    cout << "Please input the left & right: ";
    int left, right;
    cin >> left >> right;

    ListNode* result = reverseBetween(save, left, right);

    while(result != nullptr)
    {
        cout << result->val << " ";
        result = result->next;
    }

    cout << "\nReverse Success!" << endl;

    return 0;

}