#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

volatile int flag = 0;  // 告知编译器，不要优化！

void *worker_thread(void *arg) {
    // 模拟耗时操作
    sleep(5);

    // 在工作线程中修改 flag 的值
    flag = 1;

    return NULL;
}

int main() {
    pthread_t tid;
    int result;

    // 创建工作线程
    result = pthread_create(&tid, NULL, worker_thread, NULL);
    if (result != 0) {
        printf("工作线程创建失败\n");
        return 1;
    }

    // 在主线程中检查 flag 的值
    while (flag == 0) {
        // 等待 flag 的值被修改
    }

    printf("flag 的值已经被修改\n");

    return 0;
}
