#include <stdio.h>
#include <stdlib.h>
#include "head_bank.h"

void print(struct balance total_balance, struct currency *val)
    {
    int i = 0;
    int j = 0;

    for(i = 0; i < 5; i++)
	{
	printf("Name: %s,  code: %s, total balance: %d\n", val[i].currency_name, val[i].letter_code, total_balance->currency_start[i]);
	}

    for(i = 0; i < 5; i++)
        {
        printf("Name: %s,  code: %s, total balance: %d\n", val[i].currency_name, val[i].letter_code, total_balance->currency_cipher[i]);
        }
    }
