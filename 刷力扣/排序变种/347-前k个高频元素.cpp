/**
 * 题目：
 * 给你一个整数数组nums和一个整数k，请你返回其中出现频率前k高的元素。你可以按任意顺序返回答案。
 * 
 * 
 * 思路：大根堆
 */
#include "../headfile/io_for_leetcode.h"
using namespace std;

// 比较直接的思路是根据大根堆来即可
vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int, int> hash;
    // 获取每个数字出现的次数
    for_each(nums.begin(), nums.end(), [&hash](int& x) { hash[x]++; });

    auto comp = [&hash](int& a, int& b) { return hash[a] < hash[b]; };

    priority_queue<int, vector<int>, decltype(comp)> q(comp);
    
    for(auto&& p : hash)    q.push(p.first);

    vector<int> res;
    for (int i = 1; i <= k; ++i) {
        res.push_back(q.top());
        q.pop();
    }

    return res;
}

int main() {
    input input347;
    auto input_vec = input347.input_vector();
    int k;
    cin >> k;

    output output347;
    output347.output_array(topKFrequent(input_vec, k));

    return 0;
}