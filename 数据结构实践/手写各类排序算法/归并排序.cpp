#include <iostream>
#include <vector>

using namespace std;

// 为了方便测试输入输出结果，定义一个针对vector的输出函数
void printVector(const vector<int> &v1)
{
    for (auto it = v1.begin(); it != v1.end(); it++)
    {
        cout << *it << " \n"[it+1==v1.end()];    // 如果是最后一个字符则打印换行
    }
}

// 归并排序的思路：使得每个子序列有序，先排序再归并，二路归并就是每次排两个子序列
void makesort(vector<int> &v2, int l1, int r1, int l2, int r2)   // 两个子序列的左右区间， v2代表那个数组
{
    // 首先默认两个子序列已经有序了
    auto tempArray = new int[r2 - l2 + r1 - l1 + 2];    //new一个可以足够保存合并后数组大小的临时数组，因为出了循环体后会被释放(注意越界)
    int index = 0;      // 临时数组的索引
    int i = l1, j = l2; // i, j用来移动
    while (i <= r1 && j <= r2 && index < r2 - l2 + r1 - l1 + 2)     // 防越界，怕了
    {
        /* code */
        if (v2[i] <= v2[j])
        {
            tempArray[index++] = v2[i++];
        }
        else {
            tempArray[index++] = v2[j++];
        }
    }
    while (i <= r1 && index < r2 - l2 + r1 - l1 + 2)
    {
        /* code */
        tempArray[index++] = v2[i++];
    }
    while (j <= r2 && index < r2 - l2 + r1 - l1 + 2)
    {
        /* code */
        tempArray[index++] = v2[j++];
    }
    for (i = 0; i < index; i++)
    {
        v2[l1 + i] = tempArray[i];
    }
}

// 使得每个子序列有序的任务已经实现
void mergesort(vector<int> &v3, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergesort(v3, left, mid);
        mergesort(v3, mid + 1, right);
        makesort(v3, left, mid, mid + 1, right);
    }
}


int main()
{
    vector<int> test = {1, 5, 11, 8, 3, 4, 6, 9};
    int last_index = test.size() - 1;
    mergesort(test, 0, last_index);
    printVector(test);
    return 0;
}