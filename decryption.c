#include <stdio.h>
#include <stdlib.h>
#include "head_bank.h"

//--------------------decryption---------------------

void decryption (int N,
                 struct client *bank_cipher,
                 struct client *bank_new,
                 struct key *cipher,
                 struct balance *total_balance)
{
        for (int i = 0; i < N; i++)
        {
                bank_new[i].account = bank_cipher[i].account - cipher[i].key_1;
                bank_new[i].amount  = bank_cipher[i].amount  - cipher[i].key_2;
                bank_new[i].code    = bank_cipher[i].code    - cipher[i].key_3;
        };

        for (int i = 0; i < 5; i++)
        {
                total_balance -> currency_cipher[i] = 0;
                
                for (int j = 0; j < N; j++)
                {
                        if (bank_new[j].code == i)
                        {
                                total_balance -> currency_cipher[i] = total_balance -> currency_cipher[i] + bank_new[j].amount;
                        }
                }
        }
}
