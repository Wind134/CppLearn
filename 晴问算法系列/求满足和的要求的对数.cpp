/* 大体思路：
访问数组中的每个元素，只要数组中某个元素存在，设计一个以该
数组元素为下标的数组，其元素为false or true (0、1)，如果需要遍历每个元素，会引起
不必要的复杂度，因此我们第一次遇到(target-a[i])这个数被访问过的话，就可以退出循环 
*/
#include <iostream>

using namespace std;

const int maxNum = 1000001;
const int maxK = 1000000;
int a[maxNum], hashTable[maxK] = { false };     // 哈希表初始状态是访问次数0

int main()
{
    int n, k;
    cin >> n >> k;
    cin.get();
    int temp = 0, count = 0;    // 分别用来记录访问过的数以及满足要求的元素对
    for (int i = 0; i < n; i++)
    {
        if(cin >> a[i])    hashTable[a[i]] = true;
    }
    // 经过上面的循环，hash表已经保存了k-a[i]的存在信息
    for (int j = 0; j < n; j++)
    {
        if (hashTable[k - a[j]])  // 当遇到(target-a[i])这个数被访问过
        {
            if (k - a[j] == temp)   break;  // 保证不需要多余的访问
            count++;
            temp = a[j];
        }
    }
    cout << count << endl;
    return 0;
}