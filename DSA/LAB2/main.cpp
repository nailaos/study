#include <cstdio>
#include <stdlib.h>
#include "hashtable.h"

int hashingkind = 2;
int collisionkind = 1;

int main(int argc, char* argv[]) {
    int type;
    char buffer[1000]; int data;
    if (argc == 3) {
        hashingkind = atoi(argv[1]);
        collisionkind = atoi(argv[2]);
    }
    hashtable table(500001, new naive_hashing(), new linear_probe());
    switch (hashingkind) {
        case 1:
            table.setHashingStrategy(new bad_hashing());
            break;
        case 2:
            table.setHashingStrategy(new good_hashing());
            break;
        default:
            break;
    }
    switch (collisionkind) {
        case 1:
            table.setCollisionStrategy(new double_probe());
            break;
        case 2:
            table.setCollisionStrategy(new overflow_probe());
            break;
        default:
            break;
    }
    while (true) {
        scanf("%d", &type);
        if (type == 0) {
            scanf("%s", buffer); scanf("%d", &data);
            table.insert(hash_entry(buffer, data));
        } else if (type == 1) {
            scanf("%s", buffer);
            printf("%d\n", table.query(buffer));
        } else break;
    }
    return 0;
}