/*
展示了decltype的类型推断，这部分主要针对左值右值推断做区分
*/
#include <iostream>
using namespace std;

int main() {
    int&& right_ref = 3;    // right_ref本身作为右值引用，是做左值

    decltype(right_ref) r = move(right_ref);

    cout << r << endl;

    int x = 3;

    decltype((x)) y = x;    // 推断出的x类型为int&

    y = 9;  // x不出意外也会同步被更改

    cout << x << endl;

    int p_x = 3;
    int *p = &p_x;
    decltype(p) q = &x;	// q是一个指向int变量的指针

    cout << *q << endl;
    return 0;
}