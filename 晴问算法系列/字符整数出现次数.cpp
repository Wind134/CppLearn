/* 给定n个正整数，按从小到大的顺序输出每个整数的出现次数。 
自建hash表
*/
#include <iostream>
#include <string>

using namespace std;

const int MaxN = 128;       // 7位ASCII码表char类型
int hashTable[MaxN] = {0};  // 出现次数都初始化为0


int main()
{
    string str;
    cin >> str;   // 输入
    getchar();  // 接换行缓冲
    for (auto element : str)
    {
        hashTable[element]++;
    }
    // 经过上面的操作之后，我们的hash表已经填满了我们所需要的信息
    for (int j = 0; j < MaxN; j++)
    {
        if (hashTable[j])   cout << (char)j << " " << hashTable[j] << endl;
    }
    return 0;
}