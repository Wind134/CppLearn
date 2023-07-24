/*
题目：合并两个有序链表

做法：该做法核心是迭代
*/
#include "../headfile/io_for_leetcode.h"
using namespace std;

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)   // 都不带指向头节点的指针
{
    if(list1 == nullptr)    return list2;
    if(list2 == nullptr)    return list1;
    ListNode* list = new ListNode();    // 新链表的头节点
    ListNode* list1Node = list1;
    ListNode* list2Node = list2;
    if (list1Node->val < list2Node->val)
    {
        list = list1Node;
        list1Node = list1Node->next;
    }
    else
    {
        list = list2Node;
        list2Node = list2Node->next;
    }

    ListNode* listNode = new ListNode();
    listNode->next = list;

    while (list1Node != nullptr && list2Node != nullptr)
    {
        if (list1Node->val < list2Node->val)
        {
            listNode->next->next = list1Node;
            listNode->next = list1Node;
            list1Node = list1Node->next;
        }
        else
        {
            listNode->next->next = list2Node;
            listNode->next = list2Node;
            list2Node = list2Node->next;
        }
    }
    if(list1Node == nullptr)
    {
        while(list2Node != nullptr)
        {
            listNode->next->next = list2Node;
            listNode->next = list2Node;
            list2Node = list2Node->next;
        }   
    }

    if(list2Node == nullptr)
    {
        while(list1Node != nullptr)
        {
            listNode->next->next = list1Node;
            listNode->next = list1Node;
            list1Node = list1Node->next;
        }
    }
    return list;
}

int main()
{
    input input21_1, input21_2;

    auto vec1 = input21_1.input_vector();
    auto vec2 = input21_2.input_vector();

    ListNode* list1 = createList(vec1);
    
    ListNode* list2 = createList(vec2);

    ListNode* mergeList = mergeTwoLists(list1, list2);
    outputList(mergeList);

    return 0;
}