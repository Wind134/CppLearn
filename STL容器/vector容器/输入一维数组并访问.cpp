#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, num;
    cin >> n;
    vector <int> array(n);
    char ch;
    int count = 0;
    array.clear();
    while(cin >> num&&count < n)
    {
        array.push_back(num);
        count ++;
        cin.get(ch);        //等价于ch = cin.get()
        if (ch != ' ')   break;
    }
    cout << "array.size() = " << array.size() << endl;

    for (vector<int>::iterator it = array.begin(); it != array.end(); it++)
    {
        cout << *it;
        cout <<(it != array.end()) ? " ":"NULL";
    }
    return 0;
}
