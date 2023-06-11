/*
 * 给你一个无重复元素的整数数组candidates和一个目标整数target ，找出candidates中可以使数字和为目标数target的所有
 * 不同组合，并以列表形式返回。可以按任意顺序返回这些组合。candidates中的同一个数字可以无限制重复被选取。如果至少一个
 * 数字的被选数量不同，则两种组合是不同的.
 * 直觉思路：回溯策略，数组中的每个元素，都有可能是target目标值的一部分，对于数组中，每个元素而言，有选中与不选中的可能
 * 详细解释39行代码为何不能放在那个位置；
 * for循环是整个函数的一部分，通过该for循环，我们将每个数压入elem_of_result，当函数执行到边界时，target=0
 * 此时就可以将符合要求的elem_of_result放入结果中，而如果我们在函数内放入pop操作，那么函数最终到边界后
 * 返回的result是缺元素的，因为每次循环我们都pop出去了一个元素
 * 正确的方案是在循环结束后统一pop
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<pair<int, int>> freq;    // 统计每个数字出现的频率次数，会先保存好信息
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
        traceback(index + 1, target);

        int most = min(target / freq[index].first, freq[index].second);
        for (int i = 1; i <= most; ++i) 
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
    vector<int> input;
    int target;

    int elem;
    while (cin >> elem)
    {
        input.push_back(elem);
        if (cin.get() == '\n')  break;
    }

    cin >> target;
    
    auto result = combinationSum2(input, target);
    for (const auto& vector : result)
    {
        for (auto& num : vector)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}