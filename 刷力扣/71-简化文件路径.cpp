/* 
* 给你一个字符串path，表示指向某一文件或目录的Unix风格绝对路径（以 '/' 开头），请你将其转化为更加简洁的规范路径。

* 注意：'...'要视为(文件/目录)名称。

* 思路：遇到"./"则去掉"./"，遇到"/xx/../"则需要去掉前一个路径，变为"/"，遇到"//"则要变成"/"
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string simplifyPath(string& path)
{
    if (path.size() == 1) return path;

    // 去除连续的"//....等一系列特殊字符"
    int index = 0;  // 从第一个字符开始
    while ((index = path.find('/', index)) != string::npos)  // 只要找到了'/'，就进行判断处理
    {
        if (path[index + 1] == '/') // 如果该索引的下一个仍然是'/'
        {
            path.erase(path.begin() + index + 1); // 处理(释放掉)
        }
        else index++;
    }

    // 处理特殊字符
    string uni_tag1 = "./";
    string uni_tag2 = "../";

    // 最后字段是/..的形式，则等价于/../，体现在代码上的做法就是在path的最后一个位置加一个'/'
    if(*(path.end() - 1) == '.' && *(path.end() - 2) == '.' && *(path.end() - 3) == '/')
        path.push_back('/');

    // 如果最后是/.，则等价于/./   
    if(*(path.end() - 1) == '.' && *(path.end() - 2) == '/')    path.push_back('/');

    index = 0;
    while ((index = path.find(uni_tag1, index)) != string::npos)
    {
        if (path[index - 1] == '/')     // 形如"XXX/./的形式则需要进行处理"
            path.erase(path.begin() + index, path.begin() + index + 2);
        else    index++;    // 如果没找到，就从该位置的下一个位置开始
        
    }

    // "../"是最麻烦的，比如说/home/love/../，你得知道父目录love的具体信息(这种情况是不是可以使用逆向查找？)
    index = 0;
    while ((index = path.find(uni_tag2, index)) != string::npos)    // find函数描述的是首次出现的位置
    {
        if (path[index - 1] == '/') // 代表是特殊字符
        {
            // index是查找到的位置，我们基于这个位置逆向查找上一个'/'出现的位置，已经确定(index - 1)一定是'/'
            if (index - 1 == 0)
            {
                path.erase(path.begin(), path.begin() + index + 3);
                path.insert(path.begin(), '/');
                index = 0;
            }
            else
            {
                int rpos = path.rfind('/', index - 2);
                int len = index - 1 - rpos;
                path.erase(path.begin() + index - len, path.begin() + index + 3);
                index -= len;  
            }
        }
        else    index ++;    
    }
    // 去除最后的'/'
    while (*(path.end() - 1) == '/' && path.size() != 1) path.erase(path.end() - 1);
    
    return path;
}

int main()
{
    string input;

    cin >> input;

    cout << simplifyPath(input) << endl;

    return 0;
}
