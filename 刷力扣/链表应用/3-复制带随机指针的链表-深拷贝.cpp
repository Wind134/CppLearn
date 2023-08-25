/**
 * 题目：
 * 给你一个长度为n的链表，每个节点包含一个额外增加的随机指针random，该指针可以指向链表中的任何节点或空节点。
 * 构造这个链表的深拷贝。深拷贝应该正好由n个全新节点组成，其中每个新节点的值都设为其对应的原节点的值。
 * 新节点的next指针和random指针也都应指向复制链表中的新节点，并使原链表和复制链表中的这些指针能够表示相同的链表状态。
 * 复制链表中的指针都不应指向原链表中的节点。
 * 
 * 思路：
 * 主要的难点在于：要处理随机的指针所指向的结点，而问题的关键就是这个随机指针指向的结点很可能还没有new出来
 */
#include "../headfile/io_for_leetcode.h"
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* head) {
    if (!head)  return nullptr;

    map<Node*, Node*> map_node;
    auto move = head;

    while (move) {
        map_node[move] = new Node(move->val);
        move = move->next;
    }

    move = head;
    while (move) {
        map_node[move]->next = map_node[move->next];
        map_node[move]->random = map_node[move->random];
        move = move->next;
    }

    return map_node[head];
}

int main() {
    // 省略IO
}