#include <cstdio>
#include <cstdlib>
#include <ctime>

int main(int argc, char **argv) {
    srand(time(0));
    // NOTE: 天数
    int n = rand() % 101;
    printf("%d\n", n);
    // NOTE: 每一天的确诊人数
    for (int i = 0; i < n; i++)
        printf("%d ", rand() % 201);
    printf("\n");
    // NOTE: 往前追朔的天数
    unsigned int last = rand();
    unsigned int max_step = 10;
    for (int i = 0; i < n; i++) {
        last = last + 1 + (unsigned int)(rand() % max_step);
        printf("%u ", 10);
    }
    printf("\n");
    // NOTE: 不同p,q的组数
    int t = rand() % 101;
    printf("%d\n", t);
    // NOTE: 第i组询问的p,q
    for (int i = 0; i < t; i++) {
        unsigned int p = 100 + (unsigned int)(rand() % 101);
        unsigned int q = p + (unsigned int)rand();
        printf("%u %u\n", p, q);
    }
    return 0;
}
