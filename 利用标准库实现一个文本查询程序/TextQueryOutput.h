#include <iostream>
#include <memory>
#include <vector>
#include <map>
#include <set>
#include <sstream>
// #include "QueryResult.h"
using line_no = std::vector<std::string>::size_type;

class QueryResult;  // 类声明
class TextQuery
{
public:
    TextQuery(std::ifstream&);  // 构造函数，读取文件
    QueryResult query(const std::string&) const;	// 该函数返回这么一个类类型的变量
    ~TextQuery() {};
private:
    std::shared_ptr<std::vector<std::string>> file;	// 文件内容信息
    std::map<std::string,
    			std::shared_ptr<std::set<line_no>>> wm;	// map映射，保存单词和出现的行号信息
};

TextQuery::TextQuery(std::ifstream &is): file(new std::vector<std::string>)
{
    std::string text;
    while (getline(is, text))
    {
        file->push_back(text);  // 以每一行为一个元素保存文本
        int n = file->size() - 1;	// 保存行号
        std::istringstream line(text);	// 将行文本分解为单词
        std::string word;
        while (line >> word) {		// 对行中每个单词
            // 如果单词不在wm的map中，以其为下标在wm中添加一项
            auto &lines = wm[word];	// lines是一个shared_ptr，即为一个指针，指向的是set类型，且是一个引用
            if (!lines)				// 如果指针为空
                lines.reset(new std::set<line_no>);	// 分配一个新的set，即添加一个set
            lines->insert(n);	// 将行号信息写入，引用的好处体现在，如果是相同一行，该调用什么也不做。
        }
    }
}

std::string make_plural(size_t ctr, const std::string &word,
                    const std::string &ending)
                    {
                        return (ctr > 1) ? word + ending : word;
                    }


class QueryResult   // 类定义
{
friend std::ostream& print(std::ostream&, const QueryResult&);	// 定义成友元，因此print函数可以访问private部分    
private:
    std::string sought;	// 查询的单词
    std::shared_ptr<std::set<line_no>> lines;	// 出现的行号
    std::shared_ptr<std::vector<std::string>> file;	// 输入文件
public:
    QueryResult(std::string s,
               std::shared_ptr<std::set<line_no>> p,
               std::shared_ptr<std::vector<std::string>> f):	// 构造函数唯一的工作就是将参数保存在对应的数据成员中
    	sought(s), lines(p), file(f) { }
    ~QueryResult() {};
};

QueryResult TextQuery::query(const std::string &sought) const
{
    // 如果未找到sought，我们将返回一个指向此set的指针
    static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
    // 使用find而不是下标运算符来查找单词，避免将单词添加到wm中
    auto loc = wm.find(sought);
    if (loc == wm.end())
        return QueryResult(sought, nodata, file);	// 未找到，返回对象的一个拷贝
    else
        return QueryResult(sought, loc->second, file);	
}

// 打印结果
std::ostream &print(std::ostream &os, const QueryResult &qr)
{
    // 如果找到了单词，打印出现次数以及所有出现的位置
    os << qr.sought << " occurs " << qr.lines->size() << " "
        << make_plural(qr.lines->size(), "time", "s") << std::endl;
    // 打印单词出现的每一行
    for (auto num: *qr.lines)
        os << "\t(line " << num + 1 << ") "
        << *(qr.file->begin() + num) << std::endl;
    return os;
}
