/*
题目：
- 给你一个链表的头节点head和一个特定值x，请你对链表进行分隔，使得所有小于x的节点都出现在大于或等于x的节点之前。
- 你应当保留两个分区中每个节点的初始相对位置。

思路：
- 遍历链表，找到第一个大于等于x的结点，保存该结点，接着遍历；
- 遇到大于或等于x的结点，不管，遇到小于的，将那个小于的结点插入到
- 找到的那个第一个大于或者等于x的结点之前；
- 直到遍历结束

- 以下做法是基于原链表的做法，分类讨论比较多
- 但是同时可以考虑双指针的做法，写法会简洁太多
*/
#include "../headfile/io_for_leetcode.h"
using namespace std;


ListNode* partition(ListNode* head, int x)
{
    if (!head || !head->next)   return head;

    ListNode* small = new ListNode(0, head);
    ListNode* small_head = small;
    ListNode* large = new ListNode(0, head);
    ListNode* large_head = large;
    ListNode* curr = head;
    while (curr) {
        if (curr->val < x) {
            small_head->next = curr;
            small_head = small_head->next;   
        }
        else {
            large_head->next = curr;
            large_head = large_head->next;
        }
        curr = curr->next;
    }
    small_head->next = large->next;
    large_head->next = nullptr;
    
    auto res = small->next;
    delete small;
    delete large;

    return res;
}


int main()
{
    input input86;
    auto input_vec = input86.input_vector();

    ListNode* list_head = createList(input_vec);

    int target;

    cout << "Input the target: ";
    cin >> target;

    ListNode* result = partition(list_head, target);

    outputList(result);

    return 0;

}