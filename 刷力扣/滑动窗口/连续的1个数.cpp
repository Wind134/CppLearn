#include "../headfile/io_for_leetcode.h"
using namespace std;

int longestOnes(const vector<int>& nums, int k) {
    int left = 0, right = 0;
    int zeroCount = 0;  // 该变量用来记录零的数目
    int maxOnes = 0;    // 最大结果

    while (right < nums.size()) {
        if (nums[right] == 0) { // 遇到一个零，增加一个统计数目
            zeroCount++;
        }

        while (zeroCount > k) { // 如果数目超过了k个，说明超出了范围
            if (nums[left] == 0) {
                zeroCount--;
            }
            left++;
        }

        maxOnes = max(maxOnes, right - left + 1);
        right++;
    }

    return maxOnes;
}


int main() {
    input input_this;
    vector<int> nums = input_this.input_vector();

    int k;
    cout << "Please input the k: ";
    cin >> k;

    int result = longestOnes(nums, k);
    cout << "The maximum length of consecutive ones after flipping " << k << " zeroes: " << result << endl;
    return 0;
}
