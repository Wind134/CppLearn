/*
题目：要求合并K个有序链表

思路：核心思路是递归
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

    lists[minIndex] = lists[minIndex]->next;
    head->next = mergeKLists(lists);

    return head;
}

int main()
{
    int n;
    cout << "Please input array nums: ";
    cin >> n;
    vector<ListNode*> lists(n, new ListNode());
    for (int i = 0; i < n; i++)
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