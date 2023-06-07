/* 
 * 理解这个外观数列就花了很久...
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 第一项是数字 1 
 * 描述前一项，这个数是1 即“一个1”，记作"11"
 * 描述前一项，这个数是11 即 “二个1” ，记作"21"
 * 描述前一项，这个数是21 即 “一个2 + 一个1”，记作"1211"
 * 描述前一项，这个数是1211 即 “一个1 + 一个2 + 二个1” ，记作"111221"
*/
#include <iostream>
#include <string>
using namespace std;


string countAndSay(int n)
{ 
    string result = "";
    int count = 1;
    if (n == 1) return "1";
    else 
    {
        string str = countAndSay(n - 1);
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == str[i + 1])
            {
                count++;
            }
            else
            {
                result = result + to_string(count) + str[i];
                count = 1;
            }
        }
        return result;
    }
}

int main()
{
    int n;
    cin >> n;

    cout << countAndSay(n) << endl;
}