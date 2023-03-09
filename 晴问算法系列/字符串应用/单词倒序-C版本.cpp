#include <cstdio>
#include <cstring>

#define MAXW 11
#define MAXA 500 //最多的行数
char sentence[MAXA][MAXW];

void swap(char &a, char &b)
{
    char temp = a;
    a = b;
    b = temp;
}

void rword (char* a)                          //写一个函数将字符数组翻转
{
    int len_arr = strlen(a);
    for (int i = 0; i < len_arr / 2; i ++)
    {
        swap(a[i], a[len_arr - 1 - i]);
    }
}

int main()
{
    int word_num = 0;
    while (scanf("%s", sentence[word_num]) != EOF)  // 读入了一个数组就将其加1，EOF代表一个特殊的标志位
        word_num++;
    
    for (int i = 0; i < word_num; i++)
        rword(sentence[i]);

    for (int j = 0; j < word_num; j++)
    {
        printf("%s", sentence[j]);
        if (j < word_num - 1)  printf(" ");
    }
    return 0;
}