#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void GetMemory1(char* p)
{
    p = (char*)malloc(100);
}

void Test1(void)
{
    char* str = NULL;
    GetMemory1(str);
    strcpy(str, "hello world");
    printf(str);
}

char *GetMemory2(void)
{
    char p[] = "hello world";
    return p;
}

void Test2(void)
{
    char *str = NULL;
    str = GetMemory2();
    printf(str);
}
void GetMemory3(char** p, int num)
{
    *p = (char*)malloc(num);
}
void Test3(void)
{
    char* str = NULL;
    GetMemory3(&str, 100);
    strcpy(str, "hello");
    printf(str);
}
void Test4(void)
{
    char *str = (char*)malloc(100);
    strcpy(str, "hello");
    free(str);
    if(str != NULL) {
        strcpy(str, "world");
        printf(str);
    }
}

int main() {
    // Test1();
    Test2();
    Test3();
    Test4();
    return 0;
}

