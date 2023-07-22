/*
题目：
- 给你一个字符串s，请你将s分割成一些子串，使每个子串都是回文串。
- 返回s所有可能的分割方案。
- 回文串是正着读和反着读都一样的字符串。

思路：
- 一开始的反应可能是回溯，但回溯有个问题在于我们不知道该选择几个字符，有可能是两个字符的回文，有可能是整个字符的回文

- 考虑动态规划，假设我们设定一个dp_matrix，dp_matrix[i, j]表示的是s的子串s[i, j]是回文串
    -- 思考，如果s[i, j]是回文串，那如果s[i-1] = s[j + 1]，那是不是说明s[i - 1, j + 1]同样是回文串
    -- 如果s[i, j]不是回文串，那么s[i - 1, j + 1]一定也不是回文串
    -- 从矩阵的角度看，确定矩阵中某一个位置的回文串与否，就能确定右上位置的回文串
    -- 如果|i - j| = 1，直接判断s[i] = s[j]是否成立即可，不成立则非回文串
    -- 相邻位置是否是回文串，可以先判断，这样就能利用上述的矩阵递推式了
    -- 思考到这边，更正下思路，不需要动用一个矩阵，只需要矩阵的右上方部分即可，因为(j >= i)是需要成立的

- 整体的思路是对了，但是在处理dp的时候脑子一直没转过来，从底部向上处理即可    
*/
#include "../headfile/io_for_leetcode.h"
using namespace std;

vector<vector<string>> res;
vector<string> vec_of_res;

void dfs(const string& s, const vector<vector<int>>& dp, int index) {
    if (index == s.size()) {
        res.push_back(vec_of_res);
        return;
    }

    for (int i = 0; i < s.size() - index; i++) {
        if (dp[index][index + i]) {
            vec_of_res.push_back(s.substr(index, i + 1));
            dfs(s, dp, index + i + 1);
            vec_of_res.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    int size = s.size();
    vector<vector<int>> dp_matrix(size, vector<int>(size));

    for (int i = size - 1; i >= 0; i--) {
        for (int j = size - 1; j >= i; j--) { 
            if (j == i) dp_matrix[i][j] = 1;    // 如果只有一个字符串，必定相等
            else if (j - i == 1) {              // 如果是两个字符串，判断两个字符串的值即可
                if (s[i] == s[j])   dp_matrix[i][j] = 1;
            }
            else {                              // 大于两个字符串，则用递推公式
                if (dp_matrix[i + 1][j - 1] == 1 && s[i] == s[j])   dp_matrix[i][j] = 1;
            }
        }
    }
    // for (const auto& vec : dp_matrix) {
    //     for (auto& elem : vec) cout << elem << " ";
    //     cout << endl;
    // }
    dfs(s, dp_matrix, 0);

    return res;
}

int main() {
    string input;
    cin >> input;

    auto output_result = partition(input);

    output output131;
    output131.output_str_vec(output_result);
    return 0;
}