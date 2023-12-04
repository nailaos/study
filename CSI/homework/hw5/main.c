#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void doit() {
    fork();
    fork();
    printf("hello\n");
    return;
}

int main() {
    doit();
    printf("hello\n");
    exit(0);
}
