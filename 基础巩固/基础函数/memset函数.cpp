/*
memset 函数是内存赋值函数，用来给某一块内存空间进行赋值的；
包含在<string.h>头文件中,可以用它对一片内存空间逐字节进行初始化；
需要注意的一点是，对于memset而言，如果全部赋-1，或者0，不会存在误解；
但如果是赋1，以int型为例，因为int占据4个字节，是
00000001000000010000000100000001，显然这个数代表的不是1；
*/
#include <cstdio>
#include <cstring>


const int MAXN = 10;
bool a[MAXN];
int b[MAXN];

int main() {
    
    // scanf("%c", &x);
    memset(a, true, sizeof(a));    // 开辟一个空间,sizeof代表的是字节大小
    memset(b, 1, sizeof(b));
    printf("%ld\n", sizeof(a));
    printf("%d\n", a[0]);
    printf("%d\n", b[0]);
    return 0;
}
