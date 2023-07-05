/* 自定义链表节点以及一些会频繁用到的操作 */
#ifndef LISTNODE_H
#define LISTNODE_H

#include <iostream>
#include <vector>

#ifndef MIN_MAX
const int& MIN_INT = -2147483648;
const int& MAX_INT = 2147483647;
#endif

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 使用尾插法创建，以保持跟输入数组的一致性
ListNode* createList(const std::vector<int>& input_array)    // 不带指向头结点指针的链表
{
    if (input_array.size() == 0)    return nullptr;
    ListNode* head = new ListNode(input_array[0]);  // 先建立头节点
    ListNode* move_point = head;
    
    // 用迭代器，看着高级一点
    for (auto it = input_array.begin() + 1; it != input_array.end(); it++)
    {
        ListNode* new_node = new ListNode(*it);
        move_point->next = new_node;
        move_point = new_node;
    }
    return head;   
}

#endif // LISTNODE_H