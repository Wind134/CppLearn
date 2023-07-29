/*
题目：相比上题，多了一个不允许重复的条件

思路：仍然是回溯
- 数组中的每个元素，都有可能是target目标值的一部分，对于数组中，每个元素而言，有选中与不选中的可能
- 选中这个元素a[index]，那么就相当于是接着针对目标值target-a[index]寻找满足条件的组合，这就形成了一个递归
- 递归需要有返回边界，当index遍历到数组a最后一个元素时，递归结束
- 当target变为0时，说明我们已经找到了集合，将该集合加入结果，同样也返回
- 需要考虑优化的一点是，如果数组中全是一样的数应该如何处理

- 上面的做法是放进一个循环处理，如果选择不放进循环处理，是否也能有一个正常的思路
- 一个做法是引入外部哈希表，以某某index为起始点，目标值为target的哈希表，如果已经求过，就不必再回溯，通过这种方式避免重复运算
    - 暂时就不写了，思路应该是可行的
- 还有一个做法就是针对重复的元素去集中处理，下面已写出

*/
#include "../headfile/io_for_leetcode.h"
#include <algorithm>
using namespace std;


vector<pair<int, int>> freq;    // 统计每个数字出现的频率次数，会先保存好信息(用map即可)
vector<vector<int>> result;
vector<int> elem_of_result;

void traceback(int index, int target) 
{
    if (target == 0)    // 这个最好写在前面
    {
        result.push_back(elem_of_result);
        return;
    }
    if (index == freq.size())   return;
    
    
    if (target >= freq[index].first)
    {
        traceback(index + 1, target);   // 不选

        int most = min(target / freq[index].first, freq[index].second);
        for (int i = 1; i <= most; ++i) // 选1个重复的，选2个重复的...选i个重复的，针对这种情况特殊处理，也是个做法
        {
            elem_of_result.push_back(freq[index].first);
            traceback(index + 1, target - i * freq[index].first);   // 这里的index是去重后数组的index
            // elem_of_result.pop_back();  // 这一行不能放在这里，这里是循环执行的一部分
        }

        for (int i = 1; i <= most; i++)
        {
            elem_of_result.pop_back();
        }
        
    }
    else return;
    
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
{
    sort(candidates.begin(), candidates.end());
    for (int num: candidates) 
    {
        if (freq.empty() || num != freq.back().first)   freq.emplace_back(num, 1);
        else    ++freq.back().second;
    }
    traceback(0, target);
    return result;
}

int main()
{
    input input40;
    int target;

    auto vec = input40.input_vector();

    cout << "Please input the target value: ";
    cin >> target;
    
    auto result = combinationSum2(vec, target);
    
    output output40;

    output40.output_matrix(result);
    return 0;
}