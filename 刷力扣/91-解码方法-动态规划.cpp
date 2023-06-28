/* 
* 思路->动态规划：
- 假设dp[i]为字符串s中第i个字符的解码方法数
- 那么dp[i]的值取决于什么呢？
    - 如果s[i]不为0，那么显然dp[i] = dp[i - 1] + dp[i - 2];    // 这个应该不难理解，应该说是很容易理解了
        -- dp[i - 2]能不能加上，取决于s[i-1]与s[i]构成的字符是否在10~26之间，如果能，则加，否则没法加
    - 如果s[i]确为0，那么显然dp[i] = dp[i - 2];   
        - value的值取决于s[i - 1]和s[i]构成的数是否在10~26之间，如果在，那么就应该加上dp[i - 2]；
        - 否则只能为0，因为这两个数构不成一个合理的编码值；
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;


int numDecodings(string s)
{
    int size = s.size();
    if(s[0] == '0')    return 0;   // 如果存在前导0，那么返回值必定为0
    
    if(size == 1)   // 如果大小为1
    {
        int value = s[size - 1] - '0';
        return (value > 0 && value < 10) ? 1 : 0;
    }
    vector<int> dp_array(size, 0);

    dp_array[0] = 1;    // 当i在第一个位置时，必然为0，   

    int value1 = s[1] - '0';
    int value2 = (s[0] - '0') * 10 + s[1] - '0'; 
    
    // 处理dp_array[1]，需要特殊对待
    if (value1 != 0 && value2 > 9 && value2 < 27)   dp_array[1] = 2;    
    else if (value1 == 0)
    {
        if (value2 > 9 && value2 < 27)  dp_array[1] = 1;
        else    return 0;   // 直接返回，确认无法构成编码
    }
    else dp_array[1] = 1;
    for(int i = 2; i < size; i++)
    {
        if(s[i] != '0')
        {
            value1 = s[i] - '0';
            value2 = (s[i - 1] - '0') * 10 + value1;
            if (value2 > 9 && value2 < 27)  dp_array[i] = dp_array[i - 1] + dp_array[i - 2];
            else dp_array[i] = dp_array[i - 1];
        }
        else
        {
            value2 = (s[i - 1] - '0') * 10;
            if (value2 > 9 && value2 < 27)  dp_array[i] = dp_array[i - 2];
            else return 0;  // 那就无法确认编码了
        }
    }
    return dp_array[size - 1];
}

int main()
{
    string input;
    cin >> input;

    cout << numDecodings(input) << endl;

    return 0;
}
