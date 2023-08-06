/*
题目：
- 有效IP地址正好由四个整数（每个整数位于0到255之间组成，且不能含有前导0），整数之间用'.'分隔。
- 例如："0.1.2.201" 和 "192.168.1.1"是有效IP地址，但是"0.011.255.245"、"192.168.1.312"和"192.168@1.1"是无效IP地址。
- 给定一个只包含数字的字符串s，用以表示一个IP地址，返回所有可能的有效IP地址，这些地址可以通过在s中插入'.'来形成。
- 你不能重新排序或删除s中的任何数字。你可以按任何顺序返回答案。

思路：初步想法是使用回溯：
- 设定index初始值为0，那么接下来就两种情况，index要么进2，要么进3
    -- 进2的时候，判断是否是0X的情况，如果是，那么只能添加X这一位而不能添加0，这是进2的时候唯一需要特殊处理的情况
    -- 进3的时候，首先需要判断是否在0~255的范围，如果不是，那么到此为止，因为不再是一个有效的IP
        --- 如果在这个范围，就要针对00X以及0XX的情况特殊处理
*/
#include "../headfile/io_for_leetcode.h"
using namespace std;

// 两个初始都为空
vector<string> result;
string s;
int count = 0;  // 用来记录小数点的个数，小数点的个数不能超过3

void backtrace(const string& str, int index)
{
    if (count > 3)  return; // 有三个以上小数点，没有意义的IP，返回
    if (index == str.size())    // 遍历完了str的所有数据，做判断
    {
        if (count == 3)     // 如果刚好有3个小数点，则是一个合乎规则的IP
            result.push_back(s);
        return;
    }

    // 进1
    if(index + 1 <= str.size() && str[index] >= '0' && str[index] <= '9')  // 加1位
    {
        s.push_back(str[index]);
        if (index + 1 != str.size()) {
            count++;
            s.push_back('.');
        } 
        backtrace(str, index + 1);  // 加1位的情况下获取的所有的IP
        if (index + 1 != str.size()) {
            s.pop_back();
            count--; // count只有加过才需要减
        }
        s.pop_back();
    }

    // 进2    
    if (index + 2 <= str.size() && "10" <= str.substr(index, 2) && str.substr(index, 2) <= "99")
    {
        s += str.substr(index, 2);
        if (index + 2 != str.size()) {
            count++;
            s.push_back('.');
        }   
        
        backtrace(str, index + 2);
        
        if (index + 2 != str.size()) {
            count--;
            s.pop_back();
        }    
        s.pop_back();
        s.pop_back();
         
    }
    

    // 进3
    if(index + 3 <= str.size() && "100" <= str.substr(index, 3) && str.substr(index, 3) <= "255")
    {
        // 接下来的代码能执行，说明满足100~255，就要考虑特殊情况了
        if(str[index] != '0') {
            s += str.substr(index, 3);
            if (index + 3 != str.size()) {
                s.push_back('.');
                count++;
            }   
            
            backtrace(str, index + 3);
            
            if (index + 3 != str.size()) {
                count--;
                s.pop_back();
            }   
            s.pop_back();
            s.pop_back();
            s.pop_back();
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
    string str;
    cin >> str;

    auto output_res = restoreIpAddresses(str);

    output output93;
    output93.output_str_vec(output_res);
    return 0;
}