/*
题目：合并两个有序链表

做法：该做法核心是迭代
*/
#include "../headfile/io_for_leetcode.h"
using namespace std;

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)   // 都不带指向头节点的指针
{
    if (!list1 && !list2)   return nullptr;
    if (!list1 && list2) return list2;
    if (list1 && !list2) return list1;

    // 以下保证两张链表都一定在，可以用递归，也可以用迭代做
    ListNode* prev = new ListNode();
    ListNode* move_res = prev;
    ListNode* move1 = list1;
    ListNode* move2 = list2;
    while (move1 && move2) {
        if (move1->val <= move2->val) {
            move_res->next = move1;
            move1 = move1->next;
        }
        else {
            move_res->next = move2;
            move2 = move2->next;
        }
        move_res = move_res->next;
    }
    if (move1)  move_res->next = move1;
    if (move2)  move_res->next = move2;

    return prev->next;
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