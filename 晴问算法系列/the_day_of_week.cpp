/* 输入一个日期，输出星期几 */
#include <cstdio>
#include <string>
#include <iostream>

int Month_Matrix[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},    //平年
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}     //闰年
};      //建立每个月的日期映射

//直接反应可能是用数学的方式进行相加汇总，但是这样要考虑的信息实在繁杂，因此我们牺牲空间，换时间

//判断闰年与否
bool isLeapYear(int year)
{
   return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

//日期相加
void DateAddCompute(int &year, int &month, int &day)          // 引用的方式传入参数
{
    day++;  //每执行一次函数，就加1
    if (day > Month_Matrix[isLeapYear(year)][month])       //
    {
        day -= (Month_Matrix[isLeapYear(year)][month]);
        month++;
       // printf("超过了一个月\n");
    }
    if (month > 12)     //处理相加月份超过一年的情况
    {
        year++;
        month = 1;
    }
}

void DateSubCompute(int &year, int &month, int &day)          // 引用的方式传入参数
{
    day--;  //每执行一次函数，天数就减1
    if (day < 1)       //
    {
        month--;
        day = Month_Matrix[isLeapYear(year)][month];
    }
    if (month < 1)     //处理月份减完的情况
    {
        year--;
        month = 12;
        day = Month_Matrix[isLeapYear(year)][month];
    }
}

bool front_behind(int year1, int year2, int month1, int month2, int day1, int day2)
{
        if (year1 != year2)  return year1 > year2;
        else if (month1 != month2) return month1 > month2;   //只有在year1==year2时才会执行
        else if (day1 != day2)  return day1 > day2;      //只有在year1==year2且month1 == month2时才会执行
        else return NULL;   
}

int main ()
{
    //基准日期为2021-05-01，星期六(6)
    int year, month, day, count =0, dayofweek = 6;
    scanf("%d-%d-%d", &year, &month, &day);
    if (front_behind(year, 2021, month, 5, day, 1))     //如果输入的时间在基准时间后面
    {
        while (year != 2021 || month != 5 || day != 1)
        {
            DateSubCompute(year, month, day);
            count++; 
            dayofweek = (count + 6) % 7;
        }
    }
    else
    {
        while (year != 2021 || month != 5 || day != 1)
        {
            DateAddCompute(year, month, day);   // 日子在前面的处理策略是要调整的，不然会出错.......
            count++; 
            dayofweek = 6 - (count % 7);
        }
    }
    char s1[7][4]={"天", "一", "二", "三", "四", "五", "六"};    // 一个汉字占据4个char
    std::string s2;
    switch (dayofweek)
    {
    case 0:
        s2 = "天";
        break;
    
    case 1:
        s2 = "一";
        break;
    
    case 2:
        s2 = "二";
        break;
    
    case 3:
        s2 = "三";
        break;
    
    case 4:
        s2 = "四";
        break;
    
    case 5:
        s2 = "五";
        break;
    
    case 6:
        s2 = "六";
        break;
    
    default:
        break;
    }
    
    printf ("这一天是星期%s\n", s1[dayofweek]); // 如果是printf打印s2会乱码！
    std::cout << "这一天是星期" << s2 << std::endl;
    return 0;
}
