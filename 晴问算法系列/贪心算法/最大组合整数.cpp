/* 依次按序给出0～9数字的个数
输出能组合出的最大整数
 */
#include <iostream>
#include <string>
using namespace std;

const int n = 10;
int a[n];

int main()
{
    string str;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int j = n - 1; j >=0; j--)
    {
        if (a[j] != 0 && j != 0)
        {
            for (int k = 0; k < a[j]; k++)
            {
                str += to_string(j);
            }
        }
        else if(j==0)
        {
            for (int k = 0; k < a[0]; k++)
            {
                str += to_string(0);
            }
        }   
    }
    /* 处理全0的情况 */
    while (str[0] == '0')
    {
        str.erase(str.begin());
    }
    if (str.empty())
    {
        str = '0';
    }
    cout << str << endl;
    return 0;
}