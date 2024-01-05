#include <unistd.h>
#include <stdio.h>

int a = 0;

void test() { a++; }

int main() {
    int pid = fork();
    test();
    printf("a=%d\n", a);
    return 0;
}