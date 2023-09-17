/**
 * 这个问题一开始遇到应该怎么思考：
 * 缓存大小本身好说，用一个固定的容量限制即可，但是LRU的最少使用策略如何处理通过一个计数值处理是一个
 * 可以尝试的方案，每个进入缓存的key值，我们就当使用次已经有了数值1，这样可以先将缓存填满，之后，查询
 * 一个数是否在缓存中命中，命中，使用次数+1，但这种处理方式存在的一个问题在于，并不能满足最近最少使用
 * 这么一个条件，因为使用次数是总的计数；
 * 
 * 这时候就需要想怎么凸显出这个最近了，如果采用链表的方式处理这个问题，只要用到一次
 * 就将这个位置的key移动到开头，那也就是说，最近使用过的key值一定在链表头，在此之前的一定在
 * 链表头后面的那个，依此类推，问题得到解决
 * 那最后的关键在于，怎么快速让一个结点迅速移动到开头，以及怎么添加到开头
 * 那就只有双端队列了，这也就是双端队列的由来
 */

#include <unordered_map>
using std::unordered_map;

class DualLinkedNode {  // 一个双端队列的结点构造
public:   
    // 结点的构造函数，设定默认构造
    DualLinkedNode() : key(0), value(0), prev(nullptr), next(nullptr) {};

    // 设定带参构造
    DualLinkedNode(int _key, int _value) : key(_key), value(_value), 
    prev(nullptr), next(nullptr) {}

    int key, value;
    DualLinkedNode* prev;
    DualLinkedNode* next;    
};

class LRUCache {
public:
    // 初始化缓存
    LRUCache(int _capacity) {
        size = 0;
        capacity = _capacity;
        head = new DualLinkedNode();
        tail = new DualLinkedNode();
        
        // 空双向链表
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (!cache_window.count(key))   return -1;

        // 有一个细节，获取一个键值，相当于用了一次
        // 这时候要把该结点提前
        else {
            auto node = cache_window[key];
            moveToHead(node);
            return node->value;
        }

    }
    
    void put(int key, int value) {
        if (!cache_window.count(key)) { // 不存在，创建新节点
            auto node = new DualLinkedNode(key, value);

            cache_window[key] = node;   // 添加进hash
            addToHead(node);
            ++size;
            if (size > capacity) {  // 如果大小大于容量
                cache_window.erase(tail->prev->key);    // 在哈希表中删除这一块key
                removeTail();
                --size;
            }
        }
        else {
            auto node = cache_window[key];
            node->value = value;
            moveToHead(node);
        }
    }

    // 把一个结点移到头部，要先保存移动后链表之间的连接关系
    void moveToHead(DualLinkedNode* node) {
        node->next->prev = node->prev;
        node->prev->next = node->next;
        
        // 处理与哑指针的连接
        node->prev = head;
        node->next = head->next;    // 这一步细节

        // 处理与原先头结点的连接
        head->next->prev = node;
        head->next = node;
    }

    // 把一个结点加到头部，这是当缓存满了之后应该做的事
    void addToHead(DualLinkedNode* node) {
        // 处理与哑结点以及原先头结点的连接
        node->prev = head;
        node->next = head->next;    // 这一步细节
        head->next->prev = node;
        head->next = node;
    }

    // 移除那个最久未使用的键值
    void removeTail() {
        DualLinkedNode* node = tail->prev;

        node->next->prev = node->prev;
        node->prev->next = node->next;

        delete(node);   // 这个结点不再被需要了，移除掉
    }
private:
    int capacity;   // 缓存容量
    int size;       // 缓存中键值对的数量
    DualLinkedNode* head;   // 指向头部的哑指针
    DualLinkedNode* tail;   // 指向尾部的哑指针
    unordered_map<int, DualLinkedNode*> cache_window;   // 缓存窗口     
};

