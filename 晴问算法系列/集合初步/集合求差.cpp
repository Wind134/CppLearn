/* 类似前题，直接用数组写了 
题目隐含了第一个集合大于第二个集合的条件
且集合中可能有多个重复元素
*/
#include <iostream>

using namespace std;

const int maxNum = 100001;
int hashTable[maxNum] = {0};

int main()
{
    int n, m, x;    // x是要输入的数据
    cin >> n >> m;
    cin.get();
    for (int i = 0; i < n; i++)
    {
        cin >> x;   // 输入x
        hashTable[x]++;       // 访问过，标记为true
    }
    for (int i = 0; i < m; i++)
    {
        cin >> x;   // 输入x
        hashTable[x]--;       // 如果x出现在上面过，它的true变成false了
    }
    bool isFirst = true;
    for (int i = 0; i < maxNum; i++)
    {
        if (hashTable[i])   // 打印差集，但是要注意处理末尾的空格
        {    
            for (int j = 0; j < hashTable[i]; j++)
            {
                if (!isFirst)   cout << " ";
                cout << i;
                isFirst = false;
            }
        }
    }
    return 0;
}