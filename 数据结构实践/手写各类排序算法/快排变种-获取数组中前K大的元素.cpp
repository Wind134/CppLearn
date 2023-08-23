/**
 * 这个问题实质上就是使用快速，只要找到第K大的元素，就解决问题；
 * 快排的思想就是在每一轮的排序中将某个元素放到他应该放的位置上去；
 * 因此我们可以找逆序，正常的排序是从小到大，我们从大到小，对快排
 * 稍稍做一下改造即可；
 * 一旦第K大的顺序确认好位置，这个题就得到了解决；
 * 因此我们要索引索引，第K大的数索引位置应该是K - 1(第一大的在第一个，对应索引0，依次类推)
*/
#include <bits/stdc++.h>
using namespace std;

// 给定一个区间，获取每个枢轴位置的索引
// 这里需要确保begin < end，不然会有问题
int get_pivot_index(vector<int>& vec, int begin, int end) {
    int pivot = vec[begin];
    int after_pivot_index = end + 1;    // 初始化

    for (int i = end; i > begin; --i) {
        if (vec[i] <= pivot) {          // 找逆序即可
            --after_pivot_index;
            swap(vec[i], vec[after_pivot_index]);
        }
    }

    swap(vec[--after_pivot_index], vec[begin]); // 交换枢轴，谁大谁小不重要了

    return after_pivot_index;   // 上面已经自减1了，因此这里返回的是枢轴位置
}

// 假设给定的k符合数组长度的范围
int get_k_index(vector<int>& vec, int k) {
    int begin = 0;
    int end = vec.size() - 1;
    int index = -1;
    while (begin <= end) {
        index = get_pivot_index(vec, begin, end);
        if (index == k - 1) {   // 如果正好是需要的
            return index;
        }
        else if (index > k - 1) // 如果排好的是更小的，得去更大的那部分区域寻找
            end = index - 1;

        else begin = index + 1;    
    }

    return -1;
}


vector<int> TopK(vector<int>& vec, int k) {
    int k_th_elem_index = get_k_index(vec, k);

    int k_th_elem = vec[k_th_elem_index];

    vector<int> res;

    for(auto& n : vec) {
        if (n >= k_th_elem) res.push_back(n);
    }

    return res;
}


int main() {
    vector<int> input_vec;
    string input;
    int data;
    getline(cin, input);
    istringstream iss(input);
    while (iss >> data)
    {
        input_vec.push_back(data);
    }

    int k;
    cin >> k;

    auto output_res = TopK(input_vec, k);

    for (auto& e : output_res) {
        cout << e << " \n"[e == *output_res.rbegin()];
    }

    return 0;
    
}
 