/**
 * 题目：
 * 给你一个链表的头节点head，判断链表中是否有环。
 * 
 * 思路：
 * 典型的快慢指针，如果有环，快慢指针终会相遇，但是要注意的一点是：
 * 我们需要找到那个入口的位置，快慢指针是终会相遇，但他们相遇的位置不一定是
 * 入口位置，而我们要做的就是定位这个入口位置；
 */
#include "../headfile/io_for_leetcode.h"
using namespace std;

bool hasCycle(ListNode *head) {
    if (!head)  return false;

    auto fast = head;
    auto slow = head;

    while (fast && fast->next && slow) {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow)   return true;
    }

    return false;
}

int main() {
    // 不处理输入输出
}