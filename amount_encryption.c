#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "head_bank.h"

void amount_encryption (int N, struct client *bank,  struct client *bank_ciphr, struct key *ciphr)
{
    int i;
    for (i = 0; i < N; i++)
    {
        int id = (bank[i].identification_number);
        int id_first = id;
        int first = 0;
        int second = 0;

        int number_of_cif = 0;
        while (id_first > 0)
        {
           id_first = (id_first - (id_first % 10))/10;
           number_of_cif++;
        }
        id_first = id;

        while ((first % 10) == 0)
        {
            int k = 1;
            int count = 1;
            if ((id_first - (id_first % (int)pow(10, number_of_cif - k))) != 0)
            {
               first = first + (id_first - (id_first % (int)pow(10, number_of_cif - k))) * (int)pow(10, 3 - count);
               count++;
            }
            k++;
        }

        while ((second - (second % 100)) == 0)
        {
            int k = 1;
            int count = 1;
            if ((id_first % (int)pow(10, k)) != 0)
            {
                second = second + (id_first % (int)pow(10, k)) * (int)pow(10, count - 1);
                count++;
            }
            k++;
        }

        int nod_1 = nod(first, second);

        int x = ((id_first % 1000) - (id_first % 100) - (id_first % 10));
        while (x == 0)
        {
            int k = 1;
            x = ((id_first % (int)pow(10, 4 + k)) - (id_first % (int)pow(10, 3 + k))) / (int)pow(10, 3 + k);
        }
        nod_1 = nod_1 * x;

        (ciphr[i].key_2) = nod_1;
        (bank_ciphr[i].amount) = (bank[i].amount) + nod_1;
    }
}
