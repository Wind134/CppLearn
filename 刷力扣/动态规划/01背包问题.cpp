#include "../headfile/io_for_leetcode.h"
using namespace std;

int knapsack_problem1(const vector<int>& values, const vector<int>& weights, int max_weight) {
    if (values.size() == 0) return 0;
    int row = values.size();
    vector<vector<int>> dp(row, vector<int>(max_weight + 1));  // 下标从0开始
    
    for (int j = 0; j <= max_weight; ++j)   if (j >= weights[j]) dp[0][j] = values[0];
    for(int i = 1; i < row; ++i) {
        for(int j = 1; j <= max_weight; ++j) {
            if (j < weights[i])  dp[i][j] = dp[i - 1][j];
            else  dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weights[i]] + values[i]);
        }
    }

    return dp[row - 1][max_weight];
}

int main() {
    input input_knap_v;
    input input_knap_w;
    auto values = input_knap_v.input_vector();
    auto weights = input_knap_w.input_vector();

    int max;
    cin >> max;
    cout << knapsack_problem1(values, weights, max) << endl;

    return 0;
}