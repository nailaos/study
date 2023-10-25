#include<arpa/inet.h>
#include<stdio.h>
#include"byteswap.h"

void printMemory(void* p, int size) {
    unsigned char* p1 = (unsigned char*)p;
    for (int i = 0; i < size; i++)
        printf("%02x ", p1[i]);
    printf("\n");
}

int main(int argc, char const* argv[]) {
    int a = 0x12345678;
    printf("Original: ");
    printMemory(&a, sizeof(a));

    int b = byteSwap(a);
    printf("Try htonl: ");
    printMemory(&b, sizeof(b));

    a = htonl(a);
    printf("Then ntohl: ");
    printMemory(&a, sizeof(a));
}