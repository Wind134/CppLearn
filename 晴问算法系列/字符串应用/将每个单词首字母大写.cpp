#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    string word;
    vector <string> sentence;
    //下面这个循环应该也类似C语言中的scanf函数，遇到EOF会自动结束输入。
    while(cin >> word)                  // 我们认为这指令会自动识别到空格，从而将词汇push_back
        sentence.push_back(word);
    for (int it = 0; it < sentence.size(); it++) 
    {
        sentence[it][0] += ('A' - 'a');
        if (it < sentence.size() - 1)   cout << sentence[it] << " ";
        else cout << sentence[it] << endl;
    }
    return 0;
}