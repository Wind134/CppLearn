#include <iostream>
#include <string>
#include <map>
using namespace std;

// 在使用map这部分内容时有些卡壳了...
map<char, int> romanMap{{'I', 1}, {'V', 5}, {'X', 10},
                {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

int romanToInt(const string&);

int main()
{
    string input;
    cin >> input;
    cout << romanToInt(input) << endl;
}

int romanToInt(const string& s)
{
    int result = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == 'I' && s[i+1] == 'V')
        {
            result += 4;
            i += 1;
        }
        else if(s[i] == 'I' && s[i+1] == 'X')
        {
            result += 9;
            i += 1;
        }
        else if(s[i] == 'X' && s[i+1] == 'L')
        {
            result += 40;
            i += 1;
        }
        else if(s[i] == 'X' && s[i+1] == 'C')
        {
            result += 90;
            i += 1;
        }
        else if(s[i] == 'C' && s[i+1] == 'D')
        {
            result += 400;
            i += 1;
        }
        else if(s[i] == 'C' && s[i+1] == 'M')
        {
            result += 900;
            i += 1;
        }
        else
        {
            result += romanMap[s[i]];
        }    
    }
    return result;
}