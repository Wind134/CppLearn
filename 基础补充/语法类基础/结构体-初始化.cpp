/* 与其说是结构体的运用，更不如说是结构体结合列表初始化的运用 */
#include <stdio.h>
struct Point
{
    int x, y;
    Point(){}   // 好像是C++中才能用的定义...默认构造函数
    Point (int _x, int _y): x(_x), y(_y) {}
}pt[10];        // 定义结构体类型的数组十个
int main()
{
    int num = 0;
    for (int i = 1; i<=3; i++){
        for (int j = 1; j <= 3; j++)
        {
            pt[num++] = Point(i , j);    //运用了初始化的构造函数
        }
    }
    for (int i = 0; i < num; i++)
    {
        printf("结构体中所存储的坐标信息为：(%d, %d)\n", pt[i].x, pt[i].y);
    }
    return 0;
}