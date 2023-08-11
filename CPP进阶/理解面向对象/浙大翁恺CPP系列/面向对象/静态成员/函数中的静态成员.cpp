#include <cstdio>

void add()
{
    static int a = 0;    //定义一个静态整型a,并对其初始化为0
    a++;                            //a自加1
    printf("%d\n",a);
}

int main()
{
    for (int i = 0; i < 6; i++)
    {
        add();
    }
    return 0;
}