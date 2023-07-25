/*
题目：
- 将一个给定字符串s根据给定的行数numRows，以从上往下、从左到右进行Z字形排列。
- 比如输入字符串为"PAYPALISHIRING"，行数为3时，排列如下：
- P   A   H   N
- A P L S I I G
- Y   I   R
- 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。


思路：
- 按照输入矩阵的顺序遍历即可，其中有很明显的规律，一个脑筋急转弯的题目
*/
#include <iostream>
#include <string>
using namespace std;

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

int main()
{
    string s;
    int numRows;
    cin >> s >> numRows;
    cout << '"' << convert(s, numRows) << '"'<< endl;
}

