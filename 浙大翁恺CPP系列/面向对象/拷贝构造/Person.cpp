#include "Person.h"
#include <cstring>
#include <iostream>


Person::Person(const char *s) {     // 定义构造函数
    name = new char[::strlen(s) + 1];
    ::strcpy(name, s);
    std::cout << "这里执行的是构造函数部分" << std::endl;
}

Person::Person(const Person& w) {     // 定义拷贝构造函数
    name = new char[::strlen(w.name) + 1];  // +1的目的是？'\0？'
    ::strcpy(name, w.name);
    std::cout << "这里执行的是拷贝构造" << std::endl;
}

Person::~Person() {
    delete [] name;     // 删除数组
}