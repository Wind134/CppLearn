#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;
int counter = 1;  // 用于控制交替打印的计数器
const int maxCount = 10;  // 打印的最大次数

void printOdd() {
    while (counter <= maxCount) {
        if (counter % 2 != 0) {
            mtx.lock();  // 上锁
            std::cout << "Odd Thread: " << counter << std::endl;
            counter++;      // 共享资源
            mtx.unlock();  // 解锁
        }
    }
}

void printEven() {
    while (counter <= maxCount) {
        if (counter % 2 == 0) {
            mtx.lock();  // 上锁
            std::cout << "Even Thread: " << counter << std::endl;
            counter++;
            mtx.unlock();  // 解锁
        }
    }
}

int main() {
    std::thread t1(printOdd);
    std::thread t2(printEven);

    t1.join();  // 等t1线程执行完毕
    t2.join();  // 等t2线程执行完毕

    return 0;
}
