/*
下面这个类包含了一些常用的排序算法，函数参数传值的目的是为了一个示例数组可以重用于多个排序算法的测试；
各排序数组的返回类型也是数组，也是为了方便输出测试；
*/

#include "../刷力扣/headfile/io_for_leetcode.h"
using namespace std;

class sort_method {
public:
    void pivot_process(vector<int>& array, int begin, int end) {    // 给定一个范围，确定该范围的中枢数
        if (begin >= end)   return;
        int pivot = array[begin];    // 选取序列中开头元素作为基准
        int left_ptr = begin + 1;
        int right_ptr = end; 
        while (left_ptr < right_ptr) {  // 只要左右两个指针没有相遇
            // 从下面这个循环可以看出来的是：left_ptr指向的位置要么是第一个大于pivot的位置
            // 要么是到了right_ptr这个位置，可以确定的是，即便是到了这个位置，在该位置以前的数都一定是小于等于pivot的
            while (left_ptr <= right_ptr && array[left_ptr] <= pivot) {   // 找到第一个大于基准的位置
                left_ptr++;
            }
            // 从下面这个循环可以看出来的是：right_ptr指向的位置要么是第一个小于pivot的位置
            // 要么是到了left_ptr这个位置，可以确定的是，即便是到了这个位置，在该位置以后的数都一定是大于pivot的
            while (left_ptr <= right_ptr && array[right_ptr] >= pivot) {  // 找到第一个小于基准的位置
                right_ptr--;
            }

            // 经过这两个循环处理之后，要么左指针指向大于base的那个位置，右指针指向了小于base的那个位置
            // 要么循环条件退出了，如果循环条件没有退出，则交换
            if (left_ptr < right_ptr)   swap(array[left_ptr], array[right_ptr]);    // 交换两个地方的位置
        }

        // 上面循环退出的原因一定是两个索引指针相等

        if (array[right_ptr] < array[begin])   swap(array[begin], array[right_ptr]);    // pivot的位置已放置
        pivot_process(array, begin, right_ptr - 1);
        pivot_process(array, right_ptr + 1, end);
    }

    // 快速排序
    vector<int> quck_sort(vector<int> array) {
        if (array.size() == 0)  return {};
        int size = array.size();
        pivot_process(array, 0, size - 1);

        return array;
    }

    // 冒泡排序
    vector<int> bubble_sort(vector<int> array) {
        int size = array.size();
        for (int i = 0; i < size; i++) //最外层循环代表了排序趟数，总共是(n-1)趟。
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                if (array[j] > array[j + 1])
                {
                    swap(array[j], array[j + 1]);
                }
            }   
        }

        return array;
    }

    // 插入排序
    vector<int> insert_sort(vector<int> array) {
        int size = array.size();
        for (int i = 1; i < size; i++)            // 第一个肯定是有序的，因此从第二个开始
        {
            int temp = array[i];    // 有序的保存下来
            int j = i;            // 单独用j保存i，以便下面的循环
            while (j >= 1 && temp < array[j - 1])     // 满足该条件执行循环
            {
                array[j] = array[j - 1];
                j --;
            }
            array[j] = temp;
        }

        return array;
    }

    // 选择排序
    vector<int> choose_sort(vector<int> array) {
        for (int i = 0; i < array.size(); i++)
        {
            int temp = array[i];    // 第一个数
            int index = i; 
            for (int j = i + 1; j < array.size(); j++)
            {
                // 记录最小值的下标索引
                if (array[j] <= temp)
                {
                    temp = array[j];
                    index = j;    // 更新临时变量
                }   
            }
            swap(array[i], array[index]);     // 交换，交换，不是相等！    
        }

        return array;
    }    
};

int main() {
    input test;
    output res;
    auto vec = test.input_vector();
    sort_method sort_ways;

    res.output_array(vec);  // 原数组
    res.output_array(sort_ways.quck_sort(vec));
    res.output_array(sort_ways.bubble_sort(vec));
    res.output_array(sort_ways.insert_sort(vec));
    res.output_array(sort_ways.choose_sort(vec));


    return 0;
}