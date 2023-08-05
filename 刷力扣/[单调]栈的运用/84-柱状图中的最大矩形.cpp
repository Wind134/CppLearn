/*
题目：
- 给定n个非负整数，用来表示柱状图中各个柱子的高度，每个柱子彼此相邻，且宽度为1。
- 求在该柱状图中，能够勾勒出来的矩形的最大面积。

思路：先列举一个最直观的思路中心扩散；
- 对于给定的每根柱子的高度height[i]，我们基于该柱子向两边扩散，扩散所得的宽度越长；
- 显然以该柱子的高度为高的矩阵面积越大；
- 这么几根柱子能组成面积最大的矩形，也就是以某根柱子的高度为高的最大矩形，因此这个暴力算法是毫无疑问正确的；

- 但是面临的问题是时间复杂度较高，这一点会使得在Leetcode上超时；
- 超时的原因是对每根柱子的扩散都需要遍历整个数组，能否不要遍历整个数组呢？
- 这部分可以参考官方的题解，这里记录一点自己的想法：
- 对于遍历到的每根柱子，如果遍历的下一根柱子高度是严格小于该柱子的，比如说目前遍历到了某根柱子，下一根更小
- 那么显然，以该根柱子高度的矩形就得到了确认，S = height[i] * (width)，width可以直接向左延申，直到遇到比height[i]要小的那根(或者最左端)，假设为j
    -- S = height[i] * (i - j)
- 为了不考虑所谓的最左边和最右边，我们增加两个虚拟哨兵0，即两根高度为0的柱子分别在数组的最左边和最右边
- 如果遍历的下一根柱子高度更长或者高度一样，这个时候由于右边的不确定性，我们无法确定右边界；
- 此时，我们针对整个数组去考虑这个流程
- 第一根柱子，比左边的0要长，左边界确定，如果第二根更短，显然，这部分面积确定；
- 如果第二根一样长或者更长，此时我们无法确定右边的延申，这个时候应该怎么办，我们用一个栈去维护每根柱子的索引，即将第一根柱子的索引0入栈；
- 然后处理第二根柱子，如果他的下一根柱子高度一样或者也更长，显然，该柱子的索引2也要入栈，如果下一根柱子长度更短，那么该根柱子高度对应的矩形就得到了确认；
    -- S = height[2] * (2 - stack.top() - 1)；
- 假设连续得到了很多个连续递增或者更长的索引，那个时候怎么办？
    -- 下一个高度h一样或者更长，入栈，如果更短，显然，可以去确认栈顶元素对应高度的矩形面积，确认的步骤：
        --- 该高度的右边界已确认，即下一根柱子的索引，左边界呢？
        --- 弹出栈顶元素，将高度与h进行比较，如果相等，继续弹出，如果更小，左边界确认，持续这样下去，左边界一定能被确认
        --- 则得所求
    -- 答案好像是另一种处理方案，弹出一个比较一个，即便是栈中有相同高度柱子的索引，由于弹一次比一次，也不影响结果；    
*/
#include "../headfile/io_for_leetcode.h"
#include <algorithm>
#include <stack>
using namespace std;

int largestRectangleArea(vector<int>& heights)
{
    int size = heights.size();
    heights.push_back(0);   // 给数组最右添加一个值
    int result = 0;         // 储存结果的变量
    stack<int> index_stack; // 定义一个储存下标索引元素的栈
    // 将数组首元素前的索引-1入栈(假想值)，因为不存在比0更小的正整数
    // 因此建模来说，该索引永远无法出栈，干脆就添加进去，以当哨兵之用，这样不需要判断栈空
    index_stack.push(-1);

    for (int i = 0; i < size; i++)
    {
        // 如果下一个元素更小，那么显然可以确定，同时，处理完的元素就当不存在
        if (heights[i + 1] < heights[i])    
        {
            result = max(result, (i - index_stack.top()) * heights[i]);

            // 确定了该元素就完事了吗？并不是，别忘了之前有过元素入栈，如果栈顶的元素也比
            // i + 1位置的要大呢，那么栈顶下标对应的高的宽度也能确定
            while (index_stack.top() == -1 || heights[index_stack.top()] > heights[i + 1])
            {
                if (index_stack.top() == -1)    break;

                else
                {
                    // 保存栈顶元素，之后将其出栈
                    int temp = index_stack.top();

                    // 出栈
                    index_stack.pop();

                    // 宽度刚好为i - index_stack.top()
                    result = max(result, (i - index_stack.top()) * heights[temp]);
                }
            }
        }
        else    // 如果下一个元素更大或者一样大，则将索引入栈
        {
            index_stack.push(i);
        }
    }

    return result;
}


int main()
{
    input input84;
    auto input_vec = input84.input_vector();

    auto result = largestRectangleArea(input_vec);

    cout << result << endl;

    return 0;
}