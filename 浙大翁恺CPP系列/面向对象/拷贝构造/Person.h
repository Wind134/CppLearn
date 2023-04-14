#ifndef _PERSON_H
#define _PERSON_H

class Person
{
public:
    Person(const char *s);
    Person(const Person& w);    // 拷贝构造声明
    ~Person();  // 析构函数声明
    void print();
    char  *name;
};

#endif