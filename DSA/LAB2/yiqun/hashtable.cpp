#include "hashtable.h"
int naive_hashing::operator()(char *str, int N)
{
    if (str == NULL)
        return 0;
    else
        return (str[0] + N) % N;
}
int polynomial_hashing::operator()(char *str, int N)
{
    unsigned long long hash = 0;
    while (*str != '\0')
    {
        hash += 29 * hash + (int)*str;
        str++;
    }
    if (hash > N)
    {
        hash %= N;
    }
    return hash;
}
int bad_hashing::operator()(char *str, int N)
{
    unsigned long long hash = 0;
    while (*str != '\0')
    {
        hash += (int)*str;
        str++;
    }
    if (hash > N)
    {
        hash %= N;
    }
    return hash;
}
int linear_probe::operator()(hash_entry *Table, int table_size, int last_choice)
{
    return (last_choice + 1) % table_size;
}
void linear_probe::init()
{
    return; // do nothing
}
void quadraticprobing::init()
{
    i = 1;
    flag = 1;
}
int quadraticprobing::nagetive_mod(int index, int table_size)
{
    index %= table_size;
    if (index < 0)
    {
        index += table_size;
    }
    return index;
}
int quadraticprobing::operator()(hash_entry *Table, int table_size, int last_choice)
{
    int result = last_choice + i * i * flag;
    if (result < 0)
    {
        result = nagetive_mod(result, table_size);
    }
    else
    {
        result %= table_size;
    }
    if (Table[result].my_string == NULL)
    {
        return result;
    }
    else
    {
        if (flag == 1)
        {
            flag = -1;
        }
        else
        {
            flag = 1;
            i++;
        }
        return result;
    }
}
void public_overflow::init()
{
    overflow_count = 0;
}
int public_overflow::operator()(hash_entry *Table, int table_size, int last_choice)
{
    int result = overflow_count + table_size;
    overflow_count++;
    return result;
}