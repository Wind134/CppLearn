/* 不难，一个递归解决问题 */
#include "../headfile/io_for_leetcode.h"
using namespace std;


ListNode* swapPairs(ListNode* head) 
{   
    // 首先处理这俩的边界情况
    if (head == nullptr)    return nullptr;
    if (head->next == nullptr)  return head;

    ListNode* swapNode = head->next;
    head->next = swapPairs(swapNode->next);
    swapNode->next = head;
    return swapNode;
}

int main()
{
    input input24;
    auto vec = input24.input_vector();

    ListNode* list = createList(vec);
    

    ListNode* resultList = swapPairs(list);
    outputList(resultList);

    return 0;
}