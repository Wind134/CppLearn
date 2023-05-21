#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isValid(const string& s)
{
    stack<char> brackStack;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            brackStack.push(s[i]);
        }
        else   if (!brackStack.empty())
        {
            if ((brackStack.top() == '(' && s[i] == ')')
                || (brackStack.top() == '{' && s[i] == '}')
                || (brackStack.top() == '[' && s[i] == ']')) brackStack.pop();
            else return false; 
        }
        else
        {
            if (s[i] == ')' || s[i] == '}' || s[i] == ']')  return false;
        }
    }
    return brackStack.empty();
}

int main()
{
    string s;
    cin >> s;
    cout << isValid(s) << endl;
}