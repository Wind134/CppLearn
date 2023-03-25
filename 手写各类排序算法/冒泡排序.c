#include <stdio.h>
int main()
{
    int a[5] = {3, 1, 4, 5, 2};
    for (int i = 0; i < 4; i++) //最外层循环代表了排序趟数，总共是(n-1)趟。
    {
        for (int j = 0; j < 4-i; j++)
        {
            if (a[j] > a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j + 1] = temp;
            }
        }   
    }
    for (int i = 0; i <5; i++)
    {
        printf("%d%c", a[i], " \n"[i == 4]);    //这一方式完美解决了我的困惑。
    }
    return 0;
}