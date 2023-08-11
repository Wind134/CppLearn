/* 这里主要介绍两个基础C语言函数的使用 */
#include <stdio.h>

void useSscanf()
{
    int n;
    char str[100] = "123";
    sscanf(str, "%d", &n);      // 将str以整型变量的方式写入到n当中，并不是输入窗口！
    printf("%d\n", n);          
}


void useSprintf()
{
    int n = 223;
    char str[100];
    sprintf(str, "%d", n);      // 相反的方向，将n处理到为str形式！
    printf("%s\n", str);
}

// 以上两个函数是原始用法介绍，接下来用于控制格式化输出

void useSscanf_format()
{
    int n;
    double db;
    char str[100] = "2048:3.14,hello", str2[100];
    sscanf(str, "%d:%lf,%s", &n, &db, str2);      // 将str以要求的规范分别写入到变量
    printf("n = %d, db = %.2f, str2 = %s\n", n, db, str2);       
}


void useSprintf_format()
{
    int n = 12;
    double db = 3.1415;
    char str[100], str2[100] = "good";
    sprintf(str, "%d:%.2f,%s", n, db, str2);      // 将str以要求的规范分别写入到变量
    printf("str = %s\n", str);       
}

int main()
{
    useSscanf();
    useSprintf();
    useSscanf_format();
    useSprintf_format();
    return 0;
}