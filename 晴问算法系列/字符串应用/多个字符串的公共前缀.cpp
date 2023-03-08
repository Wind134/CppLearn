#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define MaxString 50

int main ()
{
    int n, prefix = 0, minLong = 50;   // 分别保存输入数，前缀长，以及最长的字符串大小
    vector<string> nstring;     // 定义n个字符串
    string str;
    cin >> n;
    getchar();                  // 用来接上面的换行缓冲'\n'
    for (int i = 0; i < n; i++)
    {
        if (getline(cin, str))
            nstring.push_back(str);
    }
    /* for (auto it = nstring.begin(); it != nstring.end(); it++)
        cout << *it << endl; */
    for (int i = 0; i < minLong; i++)
    {
        char temp = nstring[0][i];
        for (size_t j = 1; j <nstring.size(); j++)
        {
            minLong = min(minLong, (int)nstring[j].size());
            if( nstring[j][i] == temp) 
            {
                if (j == nstring.size() - 1)    prefix++;
                continue;
            }
            else break;
            // 如果内部这个循环可以走完，那么说明这边是匹配的  
        }
        if (!prefix)    break;   
    }
    if (!prefix)    cout << endl;
    else cout << nstring[0].substr(0, prefix) << endl;
    return 0;
}