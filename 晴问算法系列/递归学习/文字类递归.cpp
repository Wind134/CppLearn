/* 简单示范 */
#include <iostream>

using namespace std;

void print(int n)
{
    if (!n) cout << "讲你妹的故事啊！快点去睡觉！！！\n";
    else 
    {
        cout << "从前有座山，山上有座庙\n庙里有一个老和尚和一个小和尚\n睡前老和尚给小和尚讲故事：\n";
        print(n - 1);
        cout << "然后老和尚和小和尚就睡觉啦\n";
    }
}

int main()
{
    int n;
    cin >> n;
    print(n);
    return 0;
}