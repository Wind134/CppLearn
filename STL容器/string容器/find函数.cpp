#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str = "Thank you for your smile.";
    string str2 = "you";
    string str3 = "me";
    if (str.find(str2) != string::npos)
        cout << "The str2 position is " << str.find(str2) << endl;
    if (str.find(str2, 7) != string::npos)
        cout << "The str2 position is " << str.find(str2, 7) << endl;
    if (str.find(str3) != string::npos)
        cout << "The str3 position is" << str.find(str3) << endl;
    else
        cout << "No Position!" << endl;
    return 0;
}