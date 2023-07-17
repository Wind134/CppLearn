/*
题目：
- DNA序列由一系列核苷酸组成，缩写为'A','C','G'和'T'.
- 例如，"ACGAATTCCG"是一个DNA序列，在研究DNA时，识别DNA中的重复序列非常有用。
    -- 给定一个表示DNA序列的字符串s ，返回所有在DNA分子中出现不止一次的长度为10的序列(子字符串)。

- 常规的滑动窗口解法其实就是暴力解法：
    -- 一个一个移动
    -- 设定一个map记录出现的次数

优化思路：
    -- 位运算，因为DNA中只有四种字母，2bit位可以表示这四种字母
    -- 而要求返回一个长度为10的序列，那么只需要20个bit位
    -- 我们给定初始的18个bit位，然后可以从主串s中第一个字符串开始移动
    -- 窗口依次向右移动一个字符，那么bit位中的字符就是向左移动了两位，x->(x << 2)
    -- 又因为移动后新进了一个字符，因此x—>x | bin(s[i])，此时的比特位更新成了这个
    -- 最左边的字符又出去了，我们要将高位置为0，即x & (0000......1)，12个0，20个1   
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> findRepeatedDnaSequences(string s) {
    vector<string> res;
    if (s.size() < 10)  return res;
    map<char, int> char_to_bit = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};  // 字符->bit位的映射

    // 接下来将十个字符组成一个20个bit位的数，可以理解为要比较的初始值
    int x = 0;  // 假设前面10个字符全是A，开始比较
    for (int i = 0; i < 9; i++) {
        x = (x << 2) | char_to_bit[s[i]];
    }

    map<int, int> seq_appear;
    for (int i = 0; i <= s.size() - 10; i++) {
        x = ((x << 2) | char_to_bit[s[i + 9]]) & ((1 << 20) - 1);
        if (++seq_appear[x] == 2)   // 先加，再右边
            res.push_back(s.substr(i, 10));
    }

    return res;
}

int main() {
    string input;
    cout << "Please input the DNA sequence: ";
    cin >> input;
    auto output = findRepeatedDnaSequences(input);

    for (const auto& str : output) {
        cout << str << " ";
    }
    cout << endl;

    return 0;
}