#include <iostream>
#include <algorithm>
using namespace std;

int maxValue(int* arr, const int& len)
{
    if (len==1) return arr[0];  // 长度为1直接返回该值
    else return max(arr[len - 1], maxValue(arr, len - 1));  // 否则递归
}

int (*pmax)(int*, const int&) = maxValue;

int main()
{
   int arr[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 10};
   int len = sizeof(arr) / sizeof(*arr);
   int max_val = (*pmax)(arr, len);
   cout << max_val << endl;
   return 0;
}