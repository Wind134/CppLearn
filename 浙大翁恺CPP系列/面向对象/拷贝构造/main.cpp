#include <cstdio>
#include "Person.h"

int main ()
{
    Person p1("John");  // 构造函数

    Person p2(p1);      // 拷贝构造

    printf("p1.name=%s\n", p1.name);
    printf("p2.name=%s\n", p2.name);
    return 0;
}