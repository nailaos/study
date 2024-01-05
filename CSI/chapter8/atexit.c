#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void cleanup() { printf("cleaning up\n"); }

void fork6() {
    atexit(cleanup);
    fork();
    exit(0);
}

void fork9() {
    int child_status;
    if (fork() == 0) {
        printf("HC: hello from childn");
    } else {
        printf("HP: hello from parentn");
        wait(&child_status);
        printf("CT: child has terminatedn");
    }
    printf("Byen");
    exit();
}

int main() {
    fork6();
    return 0;
}
