#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Hello, World! This is a test.";
    char* token;

    // 分割字符串为标记并打印
    token = strtok(str, ", !.");    // 按','或' '或'!'或'.'进行分割
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, ", !.");
    }
    printf("%s", str);  // str已经被修改

    return 0;
}