#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void doit() {
    if (fork() == 0) {
        fork();
        printf("hello\n");
        exit(0);
    }
    return;
}

int main() {
    doit();
    printf("hello\n");
    exit(0);
}
