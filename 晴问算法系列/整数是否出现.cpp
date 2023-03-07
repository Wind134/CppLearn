/* 给定n个正整数，按从小到大的顺序输出每个整数的出现次数。 
自建hash表
*/
#include <iostream>

using namespace std;

const int MaxN = 100001;
int hashTable[MaxN] = {0};  // 0 ! 100内的整数出现次数都初始化为0
int a[MaxN] = {0};  // m那部分数组需要专门遍历，所以定义一个数组并初始化


int main()
{
    int n, m;  
    cin >> n >> m;   
    getchar();  
    int element;  
    for (int i = 0; i < n; i++)
    {
        cin >> element;
        hashTable[element] = 1; // 出现就标为1
    }
    // 经过上面的操作之后，我们的hash表已经填满了我们所需要的信息
    for (int j = 0; j < m; j++)
    {
        if(cin >> element)  a[j] = element; // 保存了最后一行数组的元素
    }
    for (int j = 0; j < m; j++)
    {
       cout << hashTable[a[j]] << " \n"[j==m - 1];
    }
    return 0;
}