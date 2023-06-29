/*
* 有效IP地址正好由四个整数（每个整数位于0到255之间组成，且不能含有前导0），整数之间用'.'分隔。
* 例如："0.1.2.201" 和 "192.168.1.1" 是有效IP地址，但是"0.011.255.245"、"192.168.1.312"和"192.168@1.1"是无效IP地址。
* 给定一个只包含数字的字符串s，用以表示一个IP地址，返回所有可能的有效IP地址，这些地址可以通过在s中插入'.'来形成。
* 你不能重新排序或删除s中的任何数字。你可以按任何顺序返回答案。

* 思路：初步想法是使用回溯：
- 设定index初始值为0，那么接下来就两种情况，index要么进2，要么进3
    -- 进2的时候，判断是否是0X的情况，如果是，那么只能添加X这一位而不能添加0，这是进2的时候唯一需要特殊处理的情况
    -- 进3的时候，首先需要判断是否在0~255的范围，如果不是，那么到此为止，因为不再是一个有效的IP
        --- 如果在这个范围，就要针对00X以及0XX的情况特殊处理
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 两个初始都为空
vector<string> result;
string s;
int count = 0;  // 用来记录小数点的个数

void backtrace(const string& str, int index)
{
    if (count > 3)  return; // 有三个以上小数点，没有意义的IP
    if (index == str.size())
    {
        if (count == 3)
        {
            result.push_back(s);
            return;
        }
        else    return; // 小于3的数量也不对，直接返回
    }
    
    string init_s = s;  // 保存s的初始状态，后面要用

    // 进1
    s += str[index];
    if(index + 1 < str.size())
    {
        s += '.';
        count++;
    }
    backtrace(str, index + 1);
    s = init_s; // 每经过一次回溯就得恢复一次初始状态，从而让下一次回溯使用
    if(index + 1 < str.size()) count--; // count只有加过才需要减

    // 进2    
    if (index + 2 <= str.size())
    {
        if(str[index] != '0')  s += str.substr(index, 2);
        else return;
        if(index + 2 < str.size())
        {
            s += '.';
            count++;
        }
        backtrace(str, index + 2);
        s = init_s; // 恢复执行递归之前的s的状态
        if(index + 2 < str.size()) count--;
    }
    

    // 进3
    if(index + 3 <= str.size())
    {
        if (str.substr(index, 3) > "255")    return;
        else
        {
            // 接下来的代码能执行，说明满足0~255，就要考虑特殊情况了
            if(str[index] != '0')  s += str.substr(index, 3);
            else    return;
            if(index + 3 < str.size())
            {
                s += '.';
                count++;
            }
            backtrace(str, index + 3);
            s = init_s;
            if(index + 3 < str.size()) count--;
        }
    }
}

vector<string> restoreIpAddresses(string s)
{
    if(s.size() < 4)    return  result;
    backtrace(s, 0);
    return result;
}

int main()
{
    string input;
    cin >> input;

    auto output = restoreIpAddresses(input);

    for(const auto& elem : output)
    {
        cout << elem << " ";
    }

    cout << endl;

    return 0;
}