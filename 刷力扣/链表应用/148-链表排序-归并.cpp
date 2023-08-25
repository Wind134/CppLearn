/**
 * 题目：
 * 给你链表的头结点head，请将其按升序排列并返回排序后的链表。
 * 
 * 
 * 思路：
 * 采用归并算法
 */
#include "../headfile/io_for_leetcode.h"
using namespace std;


ListNode* merge_list(ListNode* list1, ListNode* list2) {
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


/**
 * @brief 合并链表的递归子程序
 */
ListNode* sortList(ListNode* head, ListNode* tail) {
    if (head == nullptr) return nullptr;

    if (head->next == tail) {
        head->next = nullptr;
        return head;
    }

    ListNode *slow = head, *fast = head;
    while (fast != tail) {
        slow = slow->next;
        fast = fast->next;
        if (fast != tail)   fast = fast->next;
    }

    return merge_list(sortList(head, slow), sortList(slow, tail));
}

ListNode* sortList(ListNode* head) {
    return sortList(head, nullptr);
}


int main() {
    input input148;
    auto vec = input148.input_vector();

    auto list = createList(vec);
    
    auto res_list = sortList(list);

    outputList(res_list);

    return 0;
}