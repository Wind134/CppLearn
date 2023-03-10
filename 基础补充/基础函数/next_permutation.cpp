/* permutation本身就是排列组合的意思 */
#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
    int a[10] = {1, 2, 3};
    //a[0]~a[2]之间的序列需要求解next_permutation
    
    do{
        printf("%d%d%d\n", a[0], a[1], a[2]);
    }//while (next_permutation(a, a+3));      //这个a做数组开头代表的应该是地址吧，(a,a +3)代表了前三个做序列
    while (next_permutation(a, a+3));
    return 0;
}