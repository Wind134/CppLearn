/*  
* 给定一个候选人编号的集合candidates和一个目标数target，找出candidates中所有可以使数字和为target的组合。
* candidates 中的每个数字在每个组合中只能使用一次。
* 算法思想：回溯！
* 假设现在在处理的位置是index，那么接下来的方案有两种：
* 方案一：跳过当前的位置index，处理下一个，这种情况就是以下一个位置为起始位置的序列中找target的组合；
* 方案二：不跳过当前位置，尝试将当前位置的元素candidates[index]加入到elem_of_vector数组中，这种情况就是
* 以下一个位置为起始位置的序列中找target-candidates[index]的组合；这两种方案必然可以保证结果是不同的；
* 但是在方案二中要面对的一点就是：如果下一个元素值candidates[index + 1] == candidates[index]呢
* 在{2，2，3}中找target为5的值，按照上面的流程走下来就会有两种情况{2，3}与{2，3}，两个2各被用一次，重复值不符合要求
* 怎么解决这个问题呢？我们每遍历到一个2，更改下目标值，就能解决重复问题，也就是说，即便遍历相同元素，但是要匹配的目标值是不同的
* 这样就解决了重复值问题；比如说{2, 2, 3}，2出现了2次，我们在index = 0处设计一个函数，函数的方案一如上述方案一；
* 函数的方案二则这么处理，当存在相同元素时，我们一次性把这些相同元素进行处理，比如说，在处理第一个2时，将2加入elem_of_result
* 由于加入了2，那么target变成5-2=3，在剩余的{3}中寻找3的目标值，此时我们再递归处理第2个2，即将在剩余的{3}中寻找1的目标值，当
* 所有相同的目标值处理完成，将之前加入到的elem_of_target pop出去
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> del_dup;
vector<vector<int>> result;
vector<int> elem_of_result;

// void backtrace1(int index, int target)   // 回溯过程
// {
//     if(target == 0)
//     {
//         result.push_back(elem_of_result);
//         return;
//     }

//     if(index == del_dup.size() || target < del_dup[index].first)    return;

//     backtrace1(index + 1, target);

//     int handler_same = min(target / del_dup[index].first, del_dup[index].second);

//     for (int i = 1; i <= handler_same; i++)
//     {
//         elem_of_result.push_back(del_dup[index].first);
//         backtrace1(index + 1, target - i * del_dup[index].first);
//     }

//     for (int i = 0; i < handler_same; i++)
//     {
//         elem_of_result.pop_back();
//     }
// }

void backtrace2(const vector<int>& candidates, int index, int target)   // 另一种回溯思路
{
    if(target == 0)
    {
        result.push_back(elem_of_result);
        return;
    }

    // 同样是基于index的位置，由于每个位置的元素都有放或者不放的可能，放第一个，看看
    for (int i = index; i < candidates.size() && candidates[i] <= target; i++)
    {
        if (i > index && candidates[i - 1] == candidates[i])    continue;
        elem_of_result.push_back(candidates[i]);
        backtrace2(candidates, i + 1, target-candidates[i]);
        elem_of_result.pop_back();
    }
    
}

vector<vector<int>> solution(vector<int>& candidates, int target) 
{
    sort(candidates.begin(), candidates.end());     // 两种回溯思路都要求排好序
    for (int num: candidates) 
    {
        if (del_dup.empty() || num != del_dup.back().first)   del_dup.emplace_back(num, 1);
        else    ++del_dup.back().second;
    }
    // backtrace1(0, target);
    backtrace2(candidates, 0, target);
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
    
    auto result = solution(input, target);
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
