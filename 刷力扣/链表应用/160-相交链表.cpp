/**
 * 题目：
 * 给你两个单链表的头节点headA和headB，请你找出并返回两个单链表相交的起始节点。
 * 如果两个链表不存在相交节点，返回null。
 * 
 * 思路：
 * 这道题本身不难，但是有一个很巧妙的做法，在这里记录一下
 */
#include "../headfile/io_for_leetcode.h"
using namespace std;

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (!headA || !headB)   return nullptr;

    auto moveA = headA;
    auto moveB = headB;

    while (moveA || moveB)
    {
        if (moveA == moveB) return moveA;
        if (moveA) moveA = moveA->next;
        else moveA = headB;

        if (moveB)  moveB = moveB->next;
        else moveB = headA;  
    }

    return nullptr;
}

int main() {
    // 这段数据结构设计的过程暂且省去
    // 因此也无输入输出
}
