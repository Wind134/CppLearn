// 两个数组已经确定正序
// 想办法将两个有序序列组合在一起

#include "../headfile/io_for_leetcode.h"
using namespace std;


double findMedianSortedArrays(const vector<int>& nums1, const vector<int>& nums2)
{
    auto it1 = nums1.begin(), it2 = nums2.begin();
    auto array_size = nums1.size() + nums2.size();
    allocator<double> alloc;
    auto const array_p = alloc.allocate(array_size);
    //auto array_p = new double[array_size];    // 分配一个这么大的整型数组空间
    //cout << "分配的新数组空间大小为：" << array_size << endl;
    int i = 0;
    while (i < array_size && (it1 != nums1.end() || it2 != nums2.end()))
    {
        if ((it1 != nums1.end() && it2 != nums2.end()) && *it1 < *it2)
        {
            array_p[i++] = *it1;
            it1++;
        }
        else if((it1 != nums1.end() && it2 != nums2.end()) && *it1 >= *it2)
        {
            array_p[i++] = *it2;
            it2++;
        }
        else if(it1 == nums1.end() && it2 != nums2.end())
        {   
            array_p[i++] = *it2;
            it2++;
        }
        else if(it1 != nums1.end() && it2 == nums2.end())
        {
            array_p[i++] = *it1;
            it1++;
        }

    }
    //cout << "新数组实际大小为：" << array_size << endl;
    //cout << array_p[array_size/2-1] + array_p[array_size/2] << endl;
    return (array_size % 2)? array_p[array_size/2] : (array_p[array_size/2-1] + array_p[array_size/2])/2;                             // 奇数偶数转换
}

int main()
{
    input input4_1, input4_2;
    auto vec1 = input4_1.input_vector();
    auto vec2 = input4_2.input_vector();
    double value = findMedianSortedArrays(vec1, vec2);
    cout << "中位数的值为：" << value << endl;
    return 0;
}
