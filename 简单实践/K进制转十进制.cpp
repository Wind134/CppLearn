/* 这里涉及到的一个比较重要的知识点就是：
arr[i] >= '0' && arr[i] <= '9'将字符类型的范围锁定到0~9，这里是利用了ASCII码的特性。
在本题当中字符仅仅考虑数字或者字母，且字母为大写，所以才有20行的写法
 */
#include <cstdio>
#include <cstring>
#include <cmath>

const int MAX = 8;
char arr[MAX];

int main()
{
    int K;
    scanf("%s %d", arr, &K);
    int decimal = 0, index = 0;
    int len = strlen(arr);
    for (int i = len - 1; i >= 0; i--)
    {
        int str_to_num = (arr[i] >= '0' && arr[i] <= '9') ? (arr[i] - '0'):(arr[i] - 'A' + 10);  //char类型减去'0'很关键
        decimal += str_to_num * pow(K, index++);
    }
    printf("%d\n", decimal);
    return 0;
}