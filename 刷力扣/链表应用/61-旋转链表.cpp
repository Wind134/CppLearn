/*
* 给你一个链表的头节点head，旋转链表，将链表每个节点向右移动k个位置。
* 思路还是很简单的：想办法让整个链表成环，然后输出之时更新头结点的位置
* 我们可以让链表成环的过程中，获取到要成为新的头结点的那个节点.

* k的值理解为：我后面要返回的头结点就是倒数第k个节点
*/
#include "../headfile//io_for_leetcode.h"
using namespace std;


ListNode* rotateRight(ListNode* head, int k)
{
    if (head == nullptr)    return nullptr;
    if (k == 0) return head;
    // 给传入的链表尾部添加一个指向头结点的指针，同时，在这个过程中，记录下

    int count = 1;  // 获取结点数量

    ListNode* move_point = head;        // 先指向头结点
    while(move_point->next != nullptr)
    {
        count++;
        move_point = move_point->next;
    }

    if (k % count == 0) return head;    // 倍数则返回本身即可

    move_point->next = head;  // 将最后一个结点指向头结点，完成了循环单链表的创建

    move_point = head;  // 重新初始化
    ListNode* move_point_prev = nullptr;

    // 继续利用move_point
    // 再接下来，直接改变head就好了，同时要销毁最后一个结点指向头结点的那个指针
    // 要获取倒数第k个节点，只需要遍历count - k次即可(假设k不超过count的范围)
    for(int i = 0; i < count - k % count; i++) 
    {
        move_point_prev = move_point;
        move_point = move_point->next;
    }

    move_point_prev->next = nullptr;

    return move_point;

}


int main()
{
    input input61;
    auto vec = input61.input_vector();

    cout << "Please input k value: ";
    int k;

    cin >> k;

    ListNode* list_head = createList(vec);

    ListNode* result = rotateRight(list_head, k);

    outputList(result);

    cout << "Rotate Success!" << endl;

    return 0;

}