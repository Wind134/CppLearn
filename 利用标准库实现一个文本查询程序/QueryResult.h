#include <iostream>
// #include "TextQuery.h"

string make_plural(size_t ctr, const string &word,
                    const string &ending)
                    {
                        return (ctr > 1) ? word + ending : word;
                    }
class QueryResult
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
    	sought(s), lines(p), file(f) {}
    ~QueryResult() {};
    using line_no = std::vector<std::string>::size_type;
};

QueryResult TextQuery::query(const string &sought) const
{
    // 如果未找到sought，我们将返回一个指向此set的指针
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    // 使用find而不是下标运算符来查找单词，避免将单词添加到wm中
    auto loc == wm.find(sought);
    if (loc == wm.end())
        return QueryResult(sought, nodata, file);	// 未找到，返回对象的一个拷贝
    else
        return QueryResult(sought, loc->second, file);	
}

// 打印结果
ostream &print(ostream &os, const QueryResult &qr)
{
    // 如果找到了单词，打印出现次数以及所有出现的位置
    os << qr.sought << " occurs " << qr.lines->size() << " "
        << make_plural(qr.lines->size(), "time", "s") << endl;
    // 打印单词出现的每一行
    for (auto num: *qr.lines)
        os << "\t(line " << num + 1 << ") "
        << *(qr.file->begin() + num) << endl;
    return os;
}