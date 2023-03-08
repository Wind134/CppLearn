#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;
    char temp = str[0]; // 先保存首字母
    int count = 0;  // 记录每个不同字母出现的次数
    for (size_t i = 0; i < str.size(); i++)
    {    
        if (str[i] == temp) count++;
        else
        {
            cout << temp << " " << count << endl;
            temp = str[i];
            count = 1;
        }
        if (i == str.size() - 1)    cout << temp << " " << count << endl;
    }
    return 0;
}