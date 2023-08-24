/**
 * 大根堆是一颗完全二叉树，每个父节点的值一定都大于等于其子节点的值；
 * 实现一个大根堆可以使用数组，数组中第一个元素为根节点，其余元素按从上到下从左到右的顺序填充；
 * 用C语言实现，就当复习巩固；
 * 大根堆是一颗完全二叉树，因此我们可以方便的利用数组处理下标；
 * 由于设计的是大根堆，因此数组最开头的元素就是最大元素；
*/
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * @brief 交换数组中两个元素的位置
 * @param p 指针p
 * @param q 指针q
 */
void swap(int* p, int* q) {
    if (*p == *q)   return;
    int temp = *p;
    *p = *q;
    *q = temp;
}

/**
 * @brief 这是上浮操作，配合插入元素时使用，因为插入元素不需要整体协调
 * @param heap 堆
 * @param index 要调整的元素位置
 * @param len 数组长度
 */
void shiftup(int* heap, int index, int len) {
    int root_index = (index - 1) / 2;
    while (root_index >= 0 && heap[root_index] < heap[index]) {
        swap(&heap[root_index], &heap[index]);
        shiftup(heap, root_index, len);
    }
}

/**
 * @brief 这是对子树的堆化操作，该操作不会更改数组长
 * @param array 数组首地址
 * @param index 指定的索引
 * @param len 数组元素个数
 */
void heapify(int* array, int index, int len) {
    if (index >= len) {
        printf("out of range! failed!\n");
        return;
    }
    int largest_index = index;
    int left = 2 * largest_index + 1;
    if (left >= len)    return;
    if (left + 1 < len && array[left + 1] > array[left])    ++left; // 这种情况下，左节点变右节点
    if (array[largest_index] < array[left]) {
        swap(&array[largest_index], &array[left]);
        largest_index = left;
    }
    if (largest_index != index) heapify(array, largest_index, len);
}

/**
 * @brief 创建堆的函数
 * @param array 数组首地址
 * @param len 数组长
 */
void createHeap(int* array, int len) {
    int adjust_index = len / 2 - 1; // 最先需要调整的结点(父节点)
    for (int i = adjust_index; i >= 0; --i) // 从最后的父节点开始，一个一个调整前面的父节点
    {
        heapify(array, i, len);
    }
}

/**
 * @brief 向大根堆中插入一个元素
 * @param heap 数组首地址
 * @param value 要插入的值
 * @param len 传存储长度的地址
 */
void insert(int* heap, int value, int* len) {
    heap[++(*len) - 1] = value;
    shiftup(heap, (*len) - 1 , *len);
}

// // 从大根堆中删除堆顶元素
// int deleteMax(int* heap) {
   
// }

// 打印大根堆中的元素
void printMaxHeap(int* heap, size_t len) {
    printf("The Value List Of Max Heap: ");
    for (int i = 0; i < len; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main() {
    
    int array[256];

    int n;
    printf("Please input the nums of array: ");
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &array[i]);
    }

    createHeap(array, n);

    printMaxHeap(array, n);

    heapify(array, n / 2 - 1, n);

    insert(array, 10, &n);
    insert(array, 7, &n);

    printf("Max Element: %d\n", array[0]);

    printMaxHeap(array, n);

    return 0;
}
