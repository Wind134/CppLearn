// 我们将实现一个简单的文本查询程序，作为标准库相关内容的总结
// 允许用户在一个给定文件中查询单词
// 查询结果是单词在文件中出现的次数及其所在行的列表
// 如果一个单词在一行中出现多次，此行则只列出一次
// 行按照行号升序输出
#include <iostream>
#include <fstream>
#include "TextQueryOutput.h"
using namespace std;
// using line_no = std::vector<std::string>::size_type;	// 声明别名，使用行号

// 先使用TextQuery和QueryResult，该函数接受要处理的文件ifstream
void runQueries(ifstream &infile)
{
    TextQuery tq(infile);	// 通过TextQuery的读取功能读入文件内容，说明这个类需要这个功能
    // 用户交互部分
    while (true)
    {
        cout << "enter word to look for, or \"q\" to quit:\t";
        std::string s;
        if (!(cin >> s) || s == "q") break;
        print(cout, tq.query(s)) << std::endl;
    }
}


int main()
{
    ifstream file_reading("./文章.txt");
    runQueries (file_reading);
    return 0;
}