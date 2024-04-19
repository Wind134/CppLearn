#include <iostream>
using namespace std;

int main () {
    cout << "Hi" << endl;
    cout << "Hi" << flush;  // 只刷新，不带任何字符
    cout << endl << "Hi";   // 与cout << endl << "Hi" << ends输出结果一致啊;
}