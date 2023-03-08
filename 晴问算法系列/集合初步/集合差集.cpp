/* 直接用数组写了 
题目隐含了第一个集合大于第二个集合的条件*/
#include <iostream>

using namespace std;

const int maxNum = 100001;
bool hashTable[maxNum] = {false};

int main()
{
    int n, m, x;    // x是要输入的数据
    cin >> n >> m;
    cin.get();
    for (int i = 0; i < n; i++)
    {
        cin >> x;   // 输入x
        hashTable[x]  = true;       // 访问过，标记为true
    }
    for (int i = 0; i < m; i++)
    {
        cin >> x;   // 输入x
        hashTable[x]  = false;       // 如果x出现在上面过，它的true变成false了
    }
    bool isFirst = true;
    for (int i = 0; i < maxNum; i++)
    {
        if (hashTable[i])   // 打印差集，但是要注意处理末尾的空格
        {    
            if (!isFirst)   cout << " ";
            cout << i;
            isFirst = false;
        }
    }
    return 0;
}