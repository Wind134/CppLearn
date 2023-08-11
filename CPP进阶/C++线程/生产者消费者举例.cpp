#include <iostream>
#include <thread>
#include <condition_variable>

std::condition_variable condConsumer;
std::condition_variable condProducer;
std::mutex mtx;
bool ready = false;
int data = 0;

void producer() {
    std::this_thread::sleep_for(std::chrono::seconds(2)); // 模拟生产者准备数据
    std::lock_guard<std::mutex> lock(mtx);
    data = 42;  // 准备数据
    ready = true;   // 告知已准备好
    condConsumer.notify_one(); // 通知消费者数据已准备好
}

void consumer() {
    std::unique_lock<std::mutex> lock(mtx);
    while (!ready) {    // while循环会一直循环检查，这里之前改成if是不对的，因为时刻需要考虑虚假唤醒(spurious wakeups)的情况发生，配合ready才对
        condConsumer.wait(lock); // 等待生产者通知数据已准备好，这一行的唤醒，由condConsumer.notify_one()来完成，两者配合使用
    }
    std::cout << "Consumer got data: " << data << std::endl;
}

int main() {
    std::thread producerThread(producer);   // 定义生产者线程和消费者线程对象
    std::thread consumerThread(consumer);

    producerThread.join();  // 执行生产者线程，直到执行完毕
    consumerThread.join();  // 执行消费者进程，直到执行完毕

    return 0;
}
