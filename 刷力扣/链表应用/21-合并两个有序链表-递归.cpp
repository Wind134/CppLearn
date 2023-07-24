/*
题目：合并两个有序链表

做法：该做法核心是递归，直接套23题的模板，改一改
*/
#include "../headfile/io_for_leetcode.h"
using namespace std;

ListNode* mergeKLists(vector<ListNode*>& lists) 
{
    if (lists.size() == 0)  return nullptr;

    for (int i = lists.size() - 1; i >= 0; i--)     // 清除所有为空指针的元素
    {
        if (lists[i] == nullptr)   lists.erase(lists.begin() + i);
    }
    if(lists.size() == 0)   return nullptr;

    int minIndex = 0;

    for (int i = 0; i < lists.size(); i++)
    {
        minIndex = (lists[i]->val < lists[minIndex]->val) ? i : minIndex;
    }
    // 搞定头节点
    ListNode* head = lists[minIndex];
    ListNode* pointNode = new ListNode();
    pointNode->next = head;

    lists[minIndex] = lists[minIndex]->next;
    pointNode->next->next = mergeKLists(lists);
    pointNode->next = pointNode->next->next;

    return head;
}

int main()
{
    vector<ListNode*> lists(2, new ListNode());
    for (int i = 0; i < 2; i++)
    {
        input input23;
        auto vec = input23.input_vector();
        
        ListNode* list_i = createList(vec);
        lists[i] = list_i;
    }
    

    ListNode* mergeList = mergeKLists(lists);
    outputList(mergeList);

    return 0;
}