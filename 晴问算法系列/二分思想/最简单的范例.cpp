/* 故意用递归写的，锻炼一下思维
个人感觉，所谓二分查找的思想，跟双指针的思想是比较像的
left，medium，right的不断移动
 */
#include <iostream>
using namespace std;

const int MaxN = 100000;
int a[MaxN];

int BinarySearch(int a[], int m, int n, const int &target)
{
    int medium = (m + n) / 2;
    if (medium < m || medium > n)   return -1;
    if (a[medium] == target)
    {
        return medium;
    }
    else if (a[medium] > target)
    {
        return BinarySearch(a, m, medium - 1, target);
    }
    else
    {
        m = (n + medium) / 2;
        return BinarySearch(a, medium + 1, n, target);
    }
}

int main()
{
    int m, target;
    cin >> m >> target;
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    cout << BinarySearch(a, 0, m - 1, target) << endl;
}