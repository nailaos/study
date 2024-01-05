#include <unistd.h>
#include <stdio.h>

int a = 0;

void test() { a++; }

int main() {
    int pid = fork();
    if (pid != 0) pid = fork();
    test();
    if (pid != 0) test();
    printf("a=%d\n", a);
    return 0;
}