/*
下面这个类包含了一些常用的排序算法，函数参数传值的目的是为了一个示例数组可以重用于多个排序算法的测试；
各排序数组的返回类型也是数组，也是为了方便输出测试；
*/

#include "../../刷力扣/headfile/io_for_leetcode.h"
using namespace std;

class sort_method {
public:
    void pivot_process(vector<int>& array, int begin, int end) {    // 给定一个范围，确定该范围的中枢数
        if (begin >= end)   return;
        int pivot = array[begin];   // 选取序列中最后一个元素作为基准
        int after_pivot_index = end + 1;    // 这个索引始终指向第一个大于等于枢轴的位置

        // 2023-08-21更改的一种全新的快排策略：将每个大于等于枢轴的元素移动到后面去
        for(int i = end; i > begin; --i) {
            // 如果不比枢轴位置处的元素小，则更新指向位置的索引，这个等于号很关键，它保证了索引始终指向第一个大于等于枢轴的位置
            // 交换的意义在于：将索引指向位置的前一个位置的元素换成比pivot更大的；
            // 观察下面这个式子，更大的array[i]换到了后面
            if (array[i] >= pivot) {
                --after_pivot_index;
                swap(array[i], array[after_pivot_index]);
            }   
        }

        // 经过上面的循环处理完之后，after_pivot_index始终保持指向最后一个大于等于枢轴位置的元素
        // 最后把枢轴处的元素换过来
        // 也就是说枢轴的索引是after_pivot_index - 1
        swap(array[--after_pivot_index], array[begin]);
        
        pivot_process(array, begin, after_pivot_index - 1);
        pivot_process(array, after_pivot_index + 1, end);
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