/* 给定n个正整数，按从小到大的顺序输出每个整数的出现次数。 
自建hash表
*/
#include <iostream>

using namespace std;

const int MaxN = 101;
int hashTable[MaxN] = {0};  // 0 ! 100内的整数出现次数都初始化为0


int main()
{
    int n;  // 数的数目
    cin >> n;   // 输入
    getchar();  // 接换行缓冲
    int element;
    for (int i = 0; i < n; i++)
    {
        cin >> element;
        hashTable[element]++;
    }
    // 经过上面的操作之后，我们的hash表已经填满了我们所需要的信息
    for (int j = 0; j < sizeof(hashTable) / sizeof(hashTable[0]); j++)
    {
        if (hashTable[j])   cout << j << " " << hashTable[j] << endl;
    }
    return 0;
}