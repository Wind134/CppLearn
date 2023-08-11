/* 该程序最后的执行结果是：
- This is the main thread.
- This is a thread.
同时输出，这说明了两个问题，第一，主线程和子线程的执行是并行的，也就说我们说的异步的；
第二，可以通过对子线程设置一些操作以延缓主线程的执行；
*/
#include <iostream>
#include <chrono>
#include <thread>

// 线程的执行体
void threadFunction() {
    std::cout << "This is a thread." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));
}

int main() {
    // 创建线程对象，并指定执行体为 threadFunction
    std::thread myThread(threadFunction);

    // 主线程继续执行其他任务
    std::cout << "This is the main thread." << std::endl;

    // 等待子线程执行完成
    myThread.join();

    return 0;
}
