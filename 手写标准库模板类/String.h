/**
 * @brief 初步搭建一个简易版的String字符串类
 */

#include <cstddef>
#include <cstring>
#include <memory>
#include <iostream>

class String
{
private:
    char* data;
    size_t length;
public:
    String() : data(nullptr), length(0) {}  // 修改默认构造
    String(const char* str);                // 带参数的构造

    String(const String& other);            // 拷贝构造
    String& operator=(const String& other); // 拷贝赋值运算符

    String(String&& other) noexcept;                 // 移动构造
    String& operator=(String&& other) noexcept;      // 移动赋值

    const char* c_str() const { return data; }
    size_t size() const { return length; }


    ~String();                              // 析构
};

String::String(const char* str)
{
    length = std::strlen(str);
    data = new char[length + 1];
    std::strcpy(data, str);     // 把str中的数据复制过来
}

String::String(const String& other) {
    length = other.length;
    data = new char[length + 1];
    std::strcpy(data, other.data);
}

String& String::operator=(const String& other) {
    if (this != &other) {           // 若是自赋值，下面这段不会执行
        if (data)   delete [] data; // 释放原有的空间
        length = other.length;
        data = new char[length + 1];
        std::strcpy(data, other.data);
    }
    
    return *this;
}

String::String(String&& other) noexcept : data(nullptr), length(0) {
    std::swap(data, other.data);    // 指针移交，完美，其实仿照拷贝构造的方式写也可以
    std::swap(length, other.length);
}

String& String::operator=(String&& other) noexcept {
    if (this != &other) {
        delete [] data;
        std::swap(data, other.data);    // 应该没有悬空指针的风险，右值嘛，离开作用域就被回收了
        std::swap(length, other.length);
    }

    return *this;
}

String::~String()
{
    delete [] data; // 析构函数删除那片空间至关重要  
}
