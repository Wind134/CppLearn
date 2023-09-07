#include "../headfile/io_for_leetcode.h"
using namespace std;

bool is_digital(char c) {
    return '1' <= c && c <= '9';
}

string decodeString(string s) {
    string res;
    int num = 1;

    for (size_t i = 0; i < s.size(); ++i)
    {
        if (is_digital(s[i])) {
            num = s[i] - '0';
        }
        if (s[i] == '[') {
            ++i;
            string temp_str;
            while (s[i] != ']') {
                temp_str.push_back(s[i]);
                ++i;
            }
            for (int j = 0; j < num; ++j)
                res += temp_str;
            num = 1;   
        }
        if (s[i] >= 'a' && s[i] <= 'z') res.push_back(s[i]);
    }
    
    return res;
}

int main() {
    string str;
    cin >> str;
    cout << decodeString(str) << endl;

    return 0;
}