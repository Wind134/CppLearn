#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // 1. 基本的lambda表达式，其中捕获列表为空
    auto square = [](int x) {
        return x * x;
    };
    std::cout << square(3) << std::endl;  // 输出：9

    // 2. lambda进阶，使用捕获列表
    int factor = 2;
    auto multiply = [factor](int x) {
        return x * factor;
    };
    std::cout << multiply(3) << std::endl;  // 输出：6

    // 3. 在lambda再进阶，使用可变捕获列表，sum会不断变化
    int sum = 0;
    std::for_each(numbers.begin(), numbers.end(), [&sum](int x) {
        sum += x;
    });
    std::cout << sum << std::endl;  // 输出：15

    // 即便value类型没有事先说明或者定义，我们还是可以直接放进捕获列表，这里解答了我的一个疑问
    std::for_each(numbers.begin(), numbers.end(), [value = sum](int x) {
        std::cout << value + x<< " ";
    });

    // 4. 在lambda中使用返回类型推断
    auto add = [](int x, int y) -> int {
        return x + y;
    };
    std::cout << add(3, 4) << std::endl;  // 输出：7

    return 0;
}
