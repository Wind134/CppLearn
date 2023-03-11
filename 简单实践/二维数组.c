#include <stdio.h>
int main()
{
    int a[5][6] = {{3, 1, 2}, {8, 4}, {}, {1,2,3,4,5}}; // 没有的统一补0
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 6; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}