/* 寻找第一个大于等于特定值的元素，我故意用递归写的，锻炼递归思维 */
#include <iostream>
// #include <vector>
using namespace std;

const int Num = 100000;
int a[Num];

int dichotomy(int a[], int left, int right, const int& k)
{
    if (left==right && a[left] < k)    return right + 1;   // 到最后都依旧找不到大于的，那么返回末尾那个
    else
    {
        int mid = (left + right) / 2;
        {
            if (a[mid-1] < k && a[mid] >= k)    return mid; // 可以直接输出mid的条件
            else    // 其他情况，递归真好用，啥也不用管
            {
                if (a[mid] >= k)    return dichotomy(a, left, mid - 1, k);
                else   return dichotomy(a, mid + 1, right, k);       
            }        
        }
    }
}

int main ()
{
    int n, key;
    cin >> n >> key;
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << dichotomy(a, 0, n - 1, key) << endl;
}