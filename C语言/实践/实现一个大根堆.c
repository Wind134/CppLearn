/*
大根堆是一颗完全二叉树，每个父节点的值一定都大于等于其子节点的值；

实现一个大根堆可以使用数组，数组中第一个元素为根节点，其余元素按从上到下从左到右的顺序填充；

用C语言实现，就当复习巩固；

大根堆是一颗完全二叉树，因此我们可以方便的利用数组处理下标
*/
#include <stdio.h>
#include <stdlib.h>

// 定义大根堆结构
typedef struct {
    int* heapArray;   // 存储堆元素的数组
    int capacity;     // 堆的容量
    int size;         // 堆中元素的数量
} MaxHeap;

// 创建一个新的大根堆
MaxHeap* createMaxHeap(int capacity) {
    MaxHeap* heap = (MaxHeap*)malloc(sizeof(MaxHeap));
    heap->heapArray = (int*)malloc(capacity * sizeof(int));
    heap->capacity = capacity;
    heap->size = 0;
    return heap;
}

// 交换数组中两个元素的位置
void swap(int* array, int i, int j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

// 向大根堆中插入一个元素
void insert(MaxHeap* heap, int value) {
    if (heap->size == heap->capacity) {
        printf("Heap is full. Cannot insert more elements.\n");
        return;
    }
    heap->size++;
    int i = heap->size - 1;
    heap->heapArray[i] = value;

    // 调整堆，使其满足大根堆的性质
    while (i != 0 && heap->heapArray[(i - 1) / 2] < heap->heapArray[i]) {
        swap(heap->heapArray, i, (i - 1) / 2);
        i = (i - 1) / 2;
    }
}

// 从大根堆中删除堆顶元素
int deleteMax(MaxHeap* heap) {
    if (heap->size == 0) {
        printf("Heap is empty. Cannot delete any element.\n");
        return -1;
    }
    if (heap->size == 1) {
        heap->size--;
        return heap->heapArray[0];
    }

    int root = heap->heapArray[0];
    heap->heapArray[0] = heap->heapArray[heap->size - 1];
    heap->size--;

    // 调整堆，使其满足大根堆的性质
    int i = 0;
    while (1) {
        int max = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < heap->size && heap->heapArray[left] > heap->heapArray[max])
            max = left;

        if (right < heap->size && heap->heapArray[right] > heap->heapArray[max])
            max = right;

        if (max != i) {
            swap(heap->heapArray, i, max);
            i = max;
        } else {
            break;
        }
    }

    return root;
}

// 打印大根堆中的元素
void printMaxHeap(MaxHeap* heap) {
    printf("Max Heap: ");
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->heapArray[i]);
    }
    printf("\n");
}

int main() {
    MaxHeap* heap = createMaxHeap(10);  // 创建一个大小为10的大根堆

    insert(heap, 5);    // 依次插入以下各个元素，由于预先定义的大小为10，因此堆中的元素数量不能超过这个数
    insert(heap, 3);
    insert(heap, 8);
    insert(heap, 1);
    insert(heap, 10);

    printMaxHeap(heap);

    int max = deleteMax(heap);
    printf("Deleted Max Element: %d\n", max);

    printMaxHeap(heap);

    return 0;
}
