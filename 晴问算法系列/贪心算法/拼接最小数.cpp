/* 给定n个可能含有前导0的数字串，将它们按任意顺序拼接，使生成的整数最小。 */
// 思路：先将数字串排序，按照字典序排序
// 但是有个坑，比如11 53 8，按字典序是8大，因此排序11 53 8，但是最终结果是11538大还是11853大呢

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/* bool cmp(const string &a, const string &b)
{
    return a > b;
} */

int main()
{
    int n;
    cin >> n;
    vector<string> strs;
    string data;
    for (int i = 0; i < n; i++)
    {
        cin >> data;
        strs.push_back(data);
    }
    sort(strs.begin(), strs.end());
    string str_joint = "";
    for (int i = 0; i < n; i++)
    {
        str_joint += strs[i];
    }
    while (str_joint[0] == '0'&&str_joint.length() != 1)
    {
        str_joint.erase(str_joint.begin());
    }
    cout << str_joint << endl;
}
