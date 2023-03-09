/* 有n个箱子需要装上一艘轮船，已知第
i个箱子的重量为Wi，轮船的载重为W。
问在不超过轮船载重的前提下，最多能把多少个箱子装上轮船。 

思路：对箱子重量排序，小的就装上去，这样就尽可能多的上船
*/
#include <iostream>
#include <algorithm>
using namespace std;

const int MaxNums = 1000001;
int a[MaxNums];

int main()
{
    int nums, weight;
    cin >> nums >> weight;
    for (int i = 0; i < nums; i++)
    {
        cin >> a[i];
    }
    sort(a, a+nums);    // 从小到大排序
    int sumWeight = a[0];
    int boxNums = 0;
    for (int i = 1; i < nums; i++)
    {
        if (sumWeight <= weight)
        {
            boxNums ++;
            sumWeight += a[i];
        } 
        else    
        {
            sumWeight -= a[i - 1];  // 保持上回的重量
            break;
        }
    }
    cout << boxNums << " " << sumWeight << endl;
    return 0;
}
