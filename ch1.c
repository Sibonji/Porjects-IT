#include <stdio.h>
#include <stdlib.h>
#include "head_bank.h"

int Verification(int N, struct client* bank, struct client* bank_new) {
	int i = 0;                                         
	int BreakOrNot = 1;                                
	for (i = 0; (i < N) && (BreakOrNot); i ++) {
		if (bank[i].identification_number != bank_new[i].identification_number) BreakOrNot = 0;
		if (bank[i].account != bank_new[i].account) BreakOrNot = 0;
		if (bank[i].amount != bank_new[i].amount) BreakOrNot = 0;
		if (bank[i].code != bank_new[i].code) BreakOrNot = 0;
	}
	return BreakOrNot;
}

int Check(struct balance* total_balance) {
	int i = 0;
	int BreakOrNot = 1;
	for (i = 0; (i < 5) && (BreakOrNot); i++) {
		if (total_balance->currency_start[i] != total_balance->currency_cipher[i]) {
			printf("\nError! Not matching currency index is %d \n", i);
			BreakOrNot = 0;
		}
	}
	return BreakOrNot;
}
