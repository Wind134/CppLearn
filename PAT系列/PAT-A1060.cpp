/* 给出两个数，将他们保留成N位小数后的科学计数法是否相等
相等给出YES
不相等给出NO
 */
#include <string>
#include <iostream>
using namespace std;

const int MaxNum = 100;

int N;      // 所规定的有效位数
string comp_digit(string s, int& e)     // 设计这么一个函数来将输入的值转化为浮点数类型，引用可以改变实参
{
    int k = 0;  //下标
    while (s.length() >0 && s.length() < 100 && s[0] == '0')
    {
        /* 该循环处理掉了所有开头的0 */
        s.erase(s.begin());
    }       
    //处理完0之后分情况讨论，第一，如果第一位是小数点，说明要处理的是小数
    if (s[0] == '.')
    {
        s.erase(s.begin());
        while(s.length() > 0 && s[0] == '0')
        {
            /* 该循环处理小数点之后的0并同步处理指数e */
            e--, s.erase(s.begin());
        }
    }
    //第二，如果不是小数点，那就要先去掉所有的小数点，以便于进行数字的比较
    else
    {
        while (k < s.length() && s[k] != '.')
        {
            /* 这一步还是巧妙的，用小数点的位置来确定规定的浮点数形式下，指数e的值 */
            k++, e++;       
        }
        if (k < s.length())             // 在结束前碰到了小数点
            s.erase(s.begin() + k);     // 删除所有的小数点，到这里指数部分已经定型了，后续的比较也已经定型了
    }
    if (s.length() == 0)
        e = 0;      //去除0之后的s长为0,说明这个式子就是个0
    
    // 到了这里我们已经去掉了所有小数点和0,接下来就是纯比较了，不用管指数，因为已经确定了指数。我们
    // 要做的就是返回底数部分的数字
    int num = 0, length = 0;
    string res;    // 要输出的底数字符
    while(num<N)        // 这一循环是为了获取要求的精度下N的所有信息
    {
        if (length < s.length())  res += s[length++];
        else res += '0';  //当length走到最后一个索引，补上0
        num++;
    }
    return res;

}
int main ()
{
    string s1, s2, s3, s4;
    cin >> N >> s1 >> s2;
    int e1 = 0, e2 = 0;
    s3 = comp_digit(s1, e1);
    s4 = comp_digit(s2, e2);
    if (s3 == s4 && e1 == e2)
        cout << "YES 0." << s3 << "*10^" << e1 <<endl;
    else
        cout << "NO 0." << s3 << "*10^" << e1 << " 0." << s4 << "*10^" << e2 << endl;

    return 0;
}