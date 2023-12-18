#include <cstdio>
#include <ctime>
#include <iostream>
#include <fstream>
#include "hashtable.h"
using namespace std;
int main()
{
    int type;
    char buffer[1000];
    int data;
    hashtable poly_linear(800011, new polynomial_hashing(), new linear_probe());
    hashtable poly_quadratic(800011, new polynomial_hashing(), new quadraticprobing());
    hashtable poly_public(800011, new polynomial_hashing(), new public_overflow());
    hashtable bad_linear(800011, new bad_hashing(), new linear_probe());
    hashtable bad_quadratic(800011, new bad_hashing(), new quadraticprobing());
    hashtable bad_public(800011, new bad_hashing(), new public_overflow());
    hashtable *table_list[6];
    table_list[0] = &poly_linear;
    table_list[1] = &poly_quadratic;
    table_list[2] = &poly_public;
    table_list[3] = &bad_linear;
    table_list[4] = &bad_quadratic;
    table_list[5] = &bad_public;
    for (int i = 0; i < 6; i++)
    {
        hashtable table = *table_list[i];
        for (int j = 0; j < 3; j++)
        {
            string filename = "test" + to_string(j) + ".txt";
            freopen(filename.c_str(), "r", stdin);
            double start_time = clock();
            while (true)
            {
                scanf("%d", &type);
                if (type == 0)
                {
                    scanf("%s", buffer);
                    scanf("%d", &data);
                    table.insert(hash_entry(buffer, data));
                }
                else if (type == 1)
                {
                    scanf("%s", buffer);
                    printf("%d\n", table.query(buffer));
                }
                else
                    break;
            }
            double end_time = clock();
            double result = (end_time - start_time) / CLOCKS_PER_SEC;
            std::ofstream outfile;
            outfile.open("result.txt", std::ios::app);
            outfile << "type: " << i << " data_set: " << j << " time: " << result << "\n";
            outfile.close();
        }
    }
    return 0;
}