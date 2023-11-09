#include <cstdio>
#include <cstdlib>

int main() {
    system("g++ rand_input.cpp -o rand_input");
    system("g++ check_input.cpp -o check_input");
    system("g++ Risk.cpp -o Risk");
    system("g++ Risk1.cpp -o Risk1");
    system("g++ Risk2.cpp -o Risk2");
    int n = 1;
    while (1) {
        system("./rand_input > rand.in");
        if (system("./check_input < rand.in") != 0) {
            printf("invalid input!\n");
            break;
        }
        system("./Risk < rand.in > 1.out");
        system("./Risk1 < rand.in > 2.out");
        system("./Risk2 < rand.in > 3.out");
        if (system("diff 1.out 2.out") != 0) {
            printf("1 and 2 are different output!\n");
            break;
        }
        if (system("diff 1.out 3.out") != 0) {
            printf("1 ans 3 are different output!\n");
            break;
        }
        if (system("diff 2.out 3.out") != 0) {
            printf("2 and 3 are different output!\n");
            break;
        }
        printf("%d is ok\n", n);
        if (n > 999)
            break;
        n++;
    }
}
