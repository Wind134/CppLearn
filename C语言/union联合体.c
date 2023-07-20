/*
这个例子将会详细说明union联合体的使用
*/
#include <stdio.h>

// 联合体Data，空间的分配受到最大成员的大小的限制
union Data {
    int intValue;
    float floatValue;
    char stringValue[20];
};

// 联合体Value，更改其中一个变量的值会影响另一个变量
union Value {
    int intValue;
    float floatValue;
};

// 这个例子涉及位字段操作
union Register {
    struct {
        unsigned int flag1 : 1; // 位字段定义
        unsigned int flag2 : 1;
        unsigned int flag3 : 1;
        unsigned int flag4 : 1;
    } flags;
    unsigned int value;
};




int main() {
    union Data data;
    data.intValue = 42; // union空间占用等于intValue空间占用

    union Value value;
    
    value.floatValue = 3.14;
    printf("Float value: %f\n", value.floatValue);
    int int_value = value.intValue;
    printf("int_value = %d\n", int_value);  // 转换的结果是不好说的

    value.intValue = 42;
    printf("Int value: %d\n", value.intValue);
}
