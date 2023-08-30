/**
 * 题目：
 * 给你一个字符串s。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。
 * 注意，划分结果需要满足：将所有划分结果按顺序连接，得到的字符串仍然是s。
 * 返回一个表示每个字符串片段的长度的列表。
 * 
 * 思路：
 */
#include "../headfile/io_for_leetcode.h"
using namespace std;

vector<int> partitionLabels(string s) {
    int n = s.size();
    vector<int> res;
    vector<pair<int, int>> intervals(26, {-1, -1});   // 仅有26个字母
    for (int i = 0; i < n; ++i)
    {
        int index = s[i] - 'a';
        if (intervals[index].first == -1) intervals[index].first = i;
        intervals[index].second = i;
    }

    // 上述循环获取了每个字母在字符串出现的区间
    int left = 0;   // 处理窗口
    int right = intervals[s[0] - 'a'].second;
    if (right >= n - 1)  return {n};

    int farest_dis = right;

    while (right <= n - 1) {
        for (int i = left; i <= right; ++i) {
            farest_dis = max(farest_dis, intervals[s[i] - 'a'].second);
            right = farest_dis;
        }
        
        res.emplace_back(farest_dis - left + 1);
        
        if (farest_dis == n - 1) {
            break;
        }
        left = farest_dis + 1;
        right = intervals[s[left] - 'a'].second;
    }

    return res;
}

int main() {
    string str;
    cin >> str;

    auto vec_res = partitionLabels(str);

    output output763;
    output763.output_array(vec_res);

    return 0;
}