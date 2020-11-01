#include <stdio.h>
#include <stdlib.h>
#include "head_bank.h"


int main()
        {
        int i = 0;
        int N = 0;
        
	scanf("%d", &N);
        
	struct client bank[10000];
        
	struct currency val[5];
        
	struct balance total_balance;
        
	struct client bank_ciphr[10000];
        
	struct client bank_new[10000];
        
	struct key ciphr[10000];
        
	currency_reference (val);
        
	customer_base (N, bank, val, &total_balance);
        
	account_encryption (N, bank, bank_ciphr, ciphr);
        
	amount_encryption (N, bank, bank_ciphr, ciphr);
        
	code_encryption (N, bank, bank_ciphr, ciphr);
        
	decryption (N, bank_ciphr, bank_new, ciphr, &total_balance);

        Verification (N , bank, bank_new);
        
	Check (&total_balance);
	
	print (&total_balance, val);

        return 0;
        }

void customer_base (int N, struct client *bank,  struct currency *val, struct balance *total_balance)
        {
        for (int i = 0; i < N; i++)
                        {
                        scanf("%lld%d%d%d", &(bank[i].identification_number), &(bank[i].account), &(bank[i].amount), &(bank[i].code));
                        if (bank[i].code = val[0].currency_code)
                                total_balance->currency_start[0] += bank[i].amount;
                        if (bank[i].code = val[1].currency_code)
                                total_balance->currency_start[1] += bank[i].amount;
                        if (bank[i].code = val[2].currency_code)
                                total_balance->currency_start[2] += bank[i].amount;
                        if (bank[i].code = val[3].currency_code)
                                total_balance->currency_start[3] += bank[i].amount;
                        if (bank[i].code = val[4].currency_code)
                                total_balance->currency_start[4] += bank[i].amount;
                        }
	}


void currency_reference (struct currency *val)
        {
        for (int i = 0; i < 5; i++)
                {
                scanf("%s%s%d",val[i].currency_name, val[i].letter_code, &(val[i].currency_code));
                }
        }
