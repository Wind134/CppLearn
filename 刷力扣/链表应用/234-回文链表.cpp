/**
 * 题目：
 * 给你一个单链表的头节点head，请你判断该链表是否为回文链表。如果是，返回true ；否则，返回false。
 * 
 * 思路：
 * 最直接思路就是遍历链表，将所有元素存储到一个数组中；
 * 
 * 但还有一个办法就是使用递归的策略，在这里实现递归策略
 * 需要提及的是，这里用到的递归策略在树中也用到过
 */
#include "../headfile/io_for_leetcode.h"
using namespace std;

bool dfs(ListNode* head, ListNode* &comp) { // 引用传递指针，确保每次对参数的修改会影响到comp
    if (!head)  return true;    // 特殊清空

    if (dfs(head->next, comp) && head->val == comp->val) {

        // 每一次子链表判断如果通过，那么就判断子链表头结点的前一个结点，comp要向后
        // 但是比较的顺序其实是从后往前，不断推进
        // 只是被推进的被压栈了而已，递归嘛
        comp = comp->next;  // 使用引用的意义      
        return true;
    }

    return false;
}

bool isPalindrome(ListNode* head) {
    auto comp = head;
    return dfs(head, comp);
}

int main() {
    input input234;
    auto input_vec = input234.input_vector();

    auto head = createList(input_vec);

    cout << boolalpha << isPalindrome(head) << endl;

    return 0;
}