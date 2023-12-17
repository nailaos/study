#include <cstdio>
#include "hashtable.h"

int main(){
    int type;
    char buffer[1000];int data;
    hashtable table(10000,new naive_hashing(),new linear_probe());
    while(true){
        scanf("%d", &type);
        if(type == 0){
            scanf("%s", buffer);scanf("%d",&data);
            table.insert(hash_entry(buffer, data));
        }else if(type == 1){
            scanf("%s",buffer);
            printf("%d\n", table.query(buffer));
        }else break;
    }
    return 0;
}