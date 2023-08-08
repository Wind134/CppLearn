/* 展示了execvp函数的使用 */
#include <stdio.h>
#include <unistd.h>

int main() {
    char *command[] = {"ls", "-l", NULL}; // 执行的命令及参数列表

    // 调用execvp()函数执行命令，从这里可以看出来的是
    // command数组中第一个字符串一般要与执行的程序名相同，这样后面才能检测到参数
    // 因此第一个参数不用"ls"，用command[0]会更好，不需要硬编码到程序中
    execvp(command[0], command);

    // 如果execvp()函数执行失败，下面的代码会被执行
    perror("execvp() failed");
    return 1;
}
