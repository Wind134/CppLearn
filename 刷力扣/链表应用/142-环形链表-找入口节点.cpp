/**
 * 题目：
 * 给你一个链表的头节点head，判断链表中是否有环。
 * 
 * 思路：
 * 典型的快慢指针，如果有环，快慢指针终会相遇，但是要注意的一点是：
 * 我们需要找到那个入口的位置，快慢指针是终会相遇，但他们相遇的位置不一定是
 * 入口位置，而我们要做的就是定位这个入口位置；
 * 通过数学方法来确认位置；
 * 
 * 假设起点到环入口的长为a，慢指针在环里走了一段距离与快指针第一次相遇，假设这段距离为b，圆环的周长为c；
 * 显然快指针走过的距离：a + nc + b，n为相遇的次数，这个等量关系好算；
 * 那么接下来，快指针走的路呢，显然是慢指针的两倍：即2(a + b)；
 * 两式一起推导：a = nc - b = (n - 1)c + c - b；
 * (c - b)是慢指针离下一次到入口节点的距离；
 * 因此只要在n == 1时，定义一个指针ptr，指向头部即可；
 * 最终慢指针会在入口处与ptr相遇
 */
#include "../headfile/io_for_leetcode.h"
using namespace std;

ListNode *detectCycle(ListNode *head) {
    if (!head)  return nullptr;

    auto fast = head;
    auto slow = head;

    while (fast != nullptr) {
            slow = slow->next;
            if (fast->next == nullptr) {
                return nullptr;
            }
            fast = fast->next->next;
            if (fast == slow) {     // 指定了第一次相遇
                ListNode *ptr = head;
                while (ptr != slow) {   // 直到ptr与慢指针相遇
                    ptr = ptr->next;
                    slow = slow->next;
                }
                return ptr;
            }
        }
        return nullptr;
}

int main() {
    // 不处理输入输出
}