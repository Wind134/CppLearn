#include <iostream>
#include <thread>

void threadFunc_join() {
    // 执行一些耗时操作
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "join子线程执行完成" << std::endl;
}

void threadFunc_detach() {
    std::cout << "detach子线程执行完成" << std::endl;
}

int main() {
    std::thread t1(threadFunc_detach);
    t1.detach(); // 线程分离

    std::thread t2(threadFunc_join);
    t2.join();   // 等待子线程执行完成

    std::thread t3(threadFunc_detach);
    t3.detach(); // 线程分离，这一行可能不会输出值，因为main线程并不会等待
    
    std::cout << "主线程继续执行" << std::endl;
    return 0;
}
