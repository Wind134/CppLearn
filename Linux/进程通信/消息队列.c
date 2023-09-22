#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// 定义消息结构
struct msg_buffer {
    long msg_type;      // 表示消息的类型或者标识符
    char msg_text[100]; // 消息内容
};

int main () {

    // ftok函数用于生成一个唯一的键，这个键常用于标识消息队列
    // 'A'标识符在ftok函数中是一个整数值，通常用于给生成的键添加一个附加标识
    key_t key = ftok("./file", 'A');    // 生成消息队列的键值

    // msgget函数接收ftok生成的键
    // IPC_CREAT表明创建新队列，同时还有IPC_EXCL字段来防止重复创建
    int msgid = msgget(key, 0666 | IPC_CREAT);

    struct msg_buffer msg;

    if (msgid == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    pid_t child_pid = fork();

    if (child_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0) {  // 子进程
        msg.msg_type = 1;
        strcpy(msg.msg_text, "Hello from child process!");
        msgsnd(msgid, &msg, sizeof(msg), 0);
    } else {  // 父进程
        sleep(1);  // 等待一秒确保子进程已发送消息

        msgrcv(msgid, &msg, sizeof(msg), 1, 0);
        printf("Received message in parent process: %s\n", msg.msg_text);

        // 删除消息队列
        msgctl(msgid, IPC_RMID, NULL);
    }

    return 0;
}
