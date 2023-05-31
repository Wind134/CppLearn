/* N字形输入的字符串，需要从左往右逐行读取输出一个新的字符串 */
#include <iostream>
#include <string>
using namespace std;


string convert(const string&, const int&);

int main()
{
    string s;
    int numRows;
    cin >> s >> numRows;
    cout << '"' << convert(s, numRows) << '"'<< endl;
}

string convert(const string& s, const int& numRows)
{
    if (numRows == 1) return s;
    string result;  // 默认初始化
    string strArray[numRows];   // 设定一个string类型的数组
    int tag = -1;    // tag值用来计数，初始值为-1是因为index初始值为0
    int index = 0;   // string数组的索引
    for (int i = 0; i < s.size(); i++)
    {
        if (index == 0 || index == numRows - 1)   tag = -tag;
        strArray[index].push_back(s[i]);
        index += tag;    
    }
    for (int i = 0; i < numRows; i++)
    {
        result += strArray[i];
    }
    return result;
}