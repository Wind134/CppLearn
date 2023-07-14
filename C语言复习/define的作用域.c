#include <stdio.h>

// #define PI 3.14159265359

int main() {
    double radius = 5.0;
    double circumference = 2 * 3 * radius;
    
    printf("Circumference: %.2f\n", circumference);
    
    {
        #define PI 3.14 // 即便是该作用域内定义，作用域外仍然可用
        double area = PI * radius * radius;
        
        printf("Area: %.3f\n", area);
    }
    
    double volume = 4 / 3 * PI * radius * radius * radius;
    
    printf("Volume: %.3f\n", volume);
    
    return 0;
}
