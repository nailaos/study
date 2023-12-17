#ifndef SORT_H
#define SORT_H

#ifdef __cplusplus
extern "C" {
#endif

    void init(int n, const int* w, const int* x);

    void modify_weight(int i, int w);

    void modify_value(int k, int x);

    long long calculate(int k);

#ifdef __cplusplus
}
#endif

#endif