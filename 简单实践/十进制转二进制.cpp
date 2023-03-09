#include <iostream>
#include <vector>
using namespace std;


int main()
{
    vector<int> binary;     //定义一个变长数组，存储需要转换的二进制数值
    int num;
    cin >> num;
    while(num!=1)
    {
        binary.push_back(num%2);
        num /= 2;
    }
    binary.push_back(1);

    for (vector<int>::iterator it = binary.begin(); it != binary.end(); it++)
    {
        cout << *it;
    }
    cout << endl;
    for (vector<int>::iterator it = binary.end() - 1; it != binary.begin(); it--)
    {
        cout << *it;
    }
    cout << *(binary.begin());
    return 0;
}