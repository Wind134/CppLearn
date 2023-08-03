/*
题目：
- 给你一个字符串path，表示指向某一文件或目录的Unix风格绝对路径（以 '/' 开头），请你将其转化为更加简洁的规范路径。
- 注意：'...'要视为(文件/目录)名称。


思路：双指针遍历字符串
- 左指针指向路径目录的开始端，右指针指向结束端，所围成的即一个单元路径；
- 先列出一些特殊路径："./" "../"，将所获取的路径与之匹配，如匹配，需特殊处理；
- 遇到"./"或者"."则去掉"./" "."，遇到"/xx/../"则需要去掉前一个路径，变为"/"，遇到"//"则要变成"/"
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string simplifyPath(string& path)
{
    if (path.size() == 1) return path;
    string special_path1 = "./", special_path2 = "../";
    vector<string> path_array;
    path_array.push_back("/");
    int size = path.size();
    int left = 1, right = 1;
    while (right < size) {
        if (path[right] == '/') {
            ++right;
            left = right;
        }

        while (right < size && path[right] != '/') ++right; // 滑动右指针

        if (right > left) { // 对比单元路径
            string insert_path = path.substr(left, right - left + 1);
            if (insert_path == special_path2 || insert_path == "..") {
               if (path_array.size() > 1)   path_array.pop_back();
            }
            else if (insert_path != "." && insert_path != special_path1 )  path_array.push_back(insert_path);
        }
        ++right;
        left = right;
    }

    string res = "";
    for (const auto& path : path_array) res += path;

    if (res.size() > 1 && *res.rbegin() == '/') res.pop_back();

    return res;
}

int main()
{
    string input;

    cin >> input;

    cout << simplifyPath(input) << endl;

    return 0;
}
