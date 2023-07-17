/*
这是一个很好的例子，展示了浅拷贝所带来的问题
- 我所采用的是默认的拷贝构造，显然默认的拷贝构造是浅拷贝；
- 正是因为是浅拷贝，在程序结束时会出现报错；
*/
#include <iostream>
#include <string>

class Person {
private:
    std::string* name;

public:
    Person(const std::string& n) {
        name = new std::string(n);
    }

    // Person(const Person& other) {
    //     name = new std::string(*other.name);
    // }

    ~Person() {
        delete name;
    }

    void setName(const std::string& n) {
        *name = n;
    }

    std::string getName() const {
        return *name;
    }
};

int main() {
    Person person1("Alice");
    Person person2 = person1;  // 浅拷贝

    person2.setName("Bob");

    std::cout << person1.getName() << std::endl;  // 输出 "Bob"，受到修改的影响

    // 程序结束后，会先对person1执行析构，成功析构
    // 但是person2的析构就会出现问题，因为person1的析构已经删除了name指针所指向的那片空间
    // delete一个已释放的空间显然是不合法的
    return 0;
}
