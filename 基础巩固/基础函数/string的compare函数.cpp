/* std::string::compare() 函数的返回值如下：
    - 如果字符串相等，则返回值为 0。
    - 如果调用该函数的字符串小于传入的字符串，则返回值小于 0。
    - 如果调用该函数的字符串大于传入的字符串，则返回值大于 0。 */
// 具体返回值取决于ASCII码的相减值
#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string s1 = "5";
    string s2 = "3";

    int val = s1.compare(s2);
    cout <<  " val = " << val << endl;
}