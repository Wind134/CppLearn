/*
- 最常⻅的fork()⽤法是创建⼀个新的进程，然后使⽤exec()载⼊⼆进制映像，替换当前进程的
映像。
- 这种情况下，派⽣了新的进程，⽽这个⼦进程会执⾏⼀个新的⼆进制可执⾏⽂
件的映像。
- 下面这个例子就展示了这么一类的使用

-- 一个疑问，这种情况下的进程fork，OS是会选择共享还是会进行内存页复制？
*/
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
  pid_t pid = fork();

  if (pid == 0) {
    // 子进程
    std::cout << "Child process executing..." << std::endl;
    
    // 使用 exec 函数族中的其中一个函数来执行外部命令
    execl("/bin/ls", "ls", "-l", nullptr);
    
    // 如果 exec 函数执行成功，下面的代码不会被执行
    std::cout << "This line will not be printed in child process." << std::endl;
  } else if (pid > 0) {
    // 父进程
    std::cout << "Parent process waiting for child process to complete..." << std::endl;
    
    // 等待子进程的结束
    wait(NULL);
    
    std::cout << "Child process completed." << std::endl;
  } else {
    // fork 失败
    std::cerr << "Fork failed." << std::endl;
    return 1;
  }

  return 0;
}
