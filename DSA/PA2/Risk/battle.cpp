#include <bits/chrono.h>
#include <chrono>
#include <cstdio>
#include <cstdlib>

int main() {
    system("g++ rand_input.cpp -o rand_input");
    system("g++ check_input.cpp -o check_input");
    system("g++ Risk.cpp -o Risk");
    system("g++ Risk1.cpp -o Risk1");
    int n = 1;
    while (1) {
        system("./rand_input > rand.in");
        if (system("./check_input < rand.in") != 0) {
            printf("invalid input!\n");
            break;
        }
        auto startTime = std::chrono::high_resolution_clock::now();
        system("./Risk < rand.in > 1.out");
        auto endTime1 = std::chrono::high_resolution_clock::now();
        auto duration1 = std::chrono::duration_cast<std::chrono::milliseconds>(
            endTime1 - startTime);
        long long ptime1 = duration1.count();
        printf("1运行时间: %lld ms\n", ptime1);
        system("./Risk1 < rand.in > 2.out");
        auto endTime2 = std::chrono::high_resolution_clock::now();
        auto duration2 = std::chrono::duration_cast<std::chrono::milliseconds>(
            endTime2 - endTime1);
        long long ptime2 = duration2.count();
        printf("2运行时间: %lld ms\n", ptime2);
        if (system("diff 1.out 2.out") != 0) {
            printf("different output!\n");
            break;
        }
        printf("%d is ok\n", n);
        if (n > 99)
            break;
        n++;
    }
}
