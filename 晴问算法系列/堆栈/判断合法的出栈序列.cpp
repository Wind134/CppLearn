#include <iostream>
#include <stack>
using namespace std;

int main ()
{
    int count, value, top = 0; // 整数的数量以及输入值以及上一次的栈顶元素，栈顶元素默认为0
    cin >> count;
    stack<int> s;
    bool isLegal = true;    // 初始化一个值
    for (int i = 0; i < count; i++)
    {
        cin >> value;   // 输入那个要输出的值
        if (value > top)    // 如果大于栈顶的那个值，说明从栈顶那个值之后，到输入的该值的这些范围值，已入栈
        {
            for (int j = top + 1; j <= value; j++)
            {
                s.push(j);  // 入栈
            }
            top = value;    // 更新栈顶的元素
        }
        if (value == s.top())
        {
            s.pop();        // 弹出栈顶元素，但不需要更新top值
        }
        else
        {
            isLegal = false;
            break;
        }
    }
    cout << (isLegal ? "Yes" : "No") << endl;
    return 0;
}