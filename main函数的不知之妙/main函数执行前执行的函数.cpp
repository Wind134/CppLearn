#include <cstdio>
#include <iostream>
#include <functional>
using namespace std;

// 方法一，使用gcc拓展，g++亦支持(或许用gcc编译也会支持)
__attribute((constructor)) void before() {
    printf("before main 1\n");
}

// 方式二，使用全局static变量
int output1() {
    printf("before main 2\n");
    return 1;
}

// 这一行用C语言会报错，提示常量表达式中不允许函数调用
static int i = output1();

// 方式三，lambda表达式
int a = []() {
    cout << "before main 3" << endl;
    return 0;
}();    // 这个括号是必须的，因为lambda是一个匿名对象

// 或者我们换种写法，把lambda匿名对象绑定到一个函数对象
function<int()> fun([]() {cout << "before main 4\n"; return 0;});
int b = fun();

int main() {
    cout << "main function" << endl;
    return 0;
}




