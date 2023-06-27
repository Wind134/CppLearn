/* 
* 给你两个按非递减顺序排列的整数数组nums1和nums2，另有两个整数m和n，分别表示nums1和nums2中的元素数目。

* 请你合并nums2到nums1中，使合并后的数组同样按非递减顺序排列。

* 思路：这道题本身很简单，但我们可以尝试就地实现排序，不借助sort以及额外空间

* 我们尝试从后面往前面遍历，很一目了然
*/
#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    int index1 = m - 1; // nums1的移动指针
    int index2 = n - 1; // nums2的移动指针
    while (index1 >= 0 && index2 >= 0)
    {
        if (nums1[index1] >= nums2[index2])
        {
            nums1[index1 + index2 + 1] = nums1[index1];
            index1--;
        }
        else
        {
            nums1[index1 + index2 + 1]  = nums2[index2];
            index2--;
        }
    }
    while (index2 >= 0)
    {
        nums1[index2] = nums2[index2];  // 因为此时index1成为-1了
        index2--;
    }   
}

int main()
{
    int n;
    cout << "Please input the total numbers of nums1 & nums2: ";
    cin >> n;
    vector<int> nums1(n, 0);
    int m;
    cout << "Please input the actual numbers of nums1: ";
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> nums1[i];
    }

    vector<int> nums2(n - m, 0);
    for (int i = 0; i < n - m; i++)
    {
        cin >> nums2[i];
    }
    cout << "Input Processed" << endl;
    
    merge(nums1, m, nums2, n - m);

    for(auto elem : nums1)
    {
        cout << elem << " ";
    }

    cout << endl;

    return 0;
    
}