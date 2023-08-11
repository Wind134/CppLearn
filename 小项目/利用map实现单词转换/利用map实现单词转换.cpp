#include <iostream>
#include <fstream>      // 需要包含在头文件之中
#include <map>          // 需要用到map处理映射
#include <sstream>      // 用到文件流
#include <string>
#include <stdexcept>
using std::map, std::cin, std::cout, std::endl, std::ifstream, std::istringstream, std::string, std::runtime_error;

// 从文件中读取信息，并转换为map映射，因为只需要读取，所以只需要用到ifstream
map<string, string> build_Map(ifstream &read_file)  // 重要原则，智能引用
{
    map<string, string> trans_map;
    string key, value;                              // 分别存储键和值
    while (read_file >> key && getline(read_file, value))
    {
        if (value.size() > 1)    // 说明存在转换的规则
            trans_map[key] = value.substr(1);      // 这部分主要为了跳过空格，不像istringstream可以自动截取
        else  
            throw runtime_error("no rule for " + key);
    }
    return trans_map;
}

// 输出我们所需要的信息
const string &  // 返回类型
output_transform(const string &s, const map<string, string> &m)          // 两个参数，要转换的string，以及映射表map
{
    auto map_it = m.find(s);    // 迭代器，指向第一个匹配的下标位置
    if (map_it != m.cend())
        return map_it->second;  // 返回值
    else
        return s;
}

// 有了映射表，有了信息输出处理方案，应该可以进行处理了
int main()
{
    ifstream f1("./单词转换文件.txt"), f2("./要转换的文本.txt");
    auto trans_map = build_Map(f1);  // 建立映射
    string line_text;    // 存储f2中每行信息
    while (getline(f2, line_text))
    {
        istringstream stream(line_text);    // 这样就能分割每个单词了
        string word;
        bool print_space = true;
        while (stream >> word)
        {
            if (print_space)    print_space = false; // 控制第一个单词没有空格
            else    cout << " ";
            cout << output_transform(word, trans_map);  // 没有就输出原单词，否则输出映射转换后的单词
        }
        cout << endl;
    }
    return 0;
}