#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int main() {

    int pipefd[2];  // 用于存储管道的文件描述符，分别用于父子进程

    // 创建无名管道，pipefd[0]用于读取，pipefd[1]用于写入
    // 如果创建失败，则展示错误信息
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid_t child_pid = fork();  // 创建子进程

    // 如果进程创建失败，则展示有关错误信息
    if (child_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0) {  // 子进程
        close(pipefd[1]);  // 关闭写入端(子进程只负责读取，不在乎写入)

        char buffer[256];
        ssize_t bytes_read = read(pipefd[0], buffer, sizeof(buffer));

        if (bytes_read == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        printf("Child process received: %s", buffer);   // 打印出缓冲区的信息
        close(pipefd[0]);  // 关闭读取端
    } else {  // 父进程
        close(pipefd[0]);  // 关闭读取端(父进程不在乎写入，只在乎读取)

        const char *message = "Hello, child process!\n";
        ssize_t bytes_written = write(pipefd[1], message, strlen(message));

        if (bytes_written == -1) {
            perror("write");
            exit(EXIT_FAILURE);
        }

        close(pipefd[1]);  // 关闭写入端
    }

    return 0;
}
