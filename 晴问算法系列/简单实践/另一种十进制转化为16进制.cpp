#include <iostream>
#include <string>
using namespace std;

int main ()
{
    const string hexdigits = "0123456789ABCDEF";    // 下标映射哈哈哈哈
    cout << "Enter a series of numbers between 0 and 15"
            << " spearated by spaces. Hit ENTER when finished: "
            << endl;
    string result;
    string::size_type n;    //The "n" type is size_type.
    while (cin >> n)
    {
        if (n < hexdigits.size())   result += hexdigits[n];
    }
    cout << "Your hex number is - " << result << endl;
}