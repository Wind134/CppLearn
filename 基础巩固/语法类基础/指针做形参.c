/* 想让自己明白，地址做参数是可以改变变量值的 */
#include <stdio.h>
void change(int *p)
{
    *p = 233;
}
int main()
{
    int a = 1;
    int *p = &a;
    change(p);
    printf("%d\n", a);  //理论上来说，这里应该要变成了233
    return 0;
}