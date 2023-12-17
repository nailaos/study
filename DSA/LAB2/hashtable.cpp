#include "hashtable.h"
int naive_hashing::operator()(char* str, int N){
    if(str == NULL) return 0;
    else return (str[0]+N)%N;
}

int linear_probe::operator()(hash_entry* Table, int table_size, int last_choice){
    return (last_choice + 1) % table_size;
}
void linear_probe::init(){
    return;// do nothing
}