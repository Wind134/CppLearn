#include <iostream>
#include <iomanip>
using namespace std;

void setDecimalPrecision(const double& d)
{
    double d1 = d;
    cout << "下面两行为setprecision的效果，效果为3和9" <<endl;
    cout << setprecision(3);	// 设置数字个数，即保留两位小数
    cout << d1 <<endl;

    cout <<setprecision(9);
    cout << d1 << endl;
}

void charFill(const char& c)
{
    cout << "下面两行作为对比setfill和setw的效果范围:" << endl;
    cout << setfill(c) << setw(8);  // 填充字符设置，包括输出总共八位
    cout << 100 << endl;    // 生效于这一行
    cout << 100 << endl;    // 常规输出
}

void hexConvert(const int& i)
{
    cout << "设置十六进制输出且需要前缀并大写字母：" <<endl;
    cout << hex;   // 代表十六进制
    cout << setiosflags(ios::showbase | ios::uppercase);   // 且需要前缀并且要大写
    cout << i <<endl;
}

int main(){
    double pi=3.1415926;
    int num = 96;
    setDecimalPrecision(pi);
    charFill('*');
    hexConvert(num);   
}