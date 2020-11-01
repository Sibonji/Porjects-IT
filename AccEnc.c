#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "head_bank.h"


unsigned check_bit (char* in, unsigned i) {
	unsigned nbyte = i / 8;
	unsigned nbit = i % 8;
	return (in[nbyte] >> nbit) & 1u;
}

void set_bit (char* in, unsigned i) {
	unsigned nbyte = i / 8;
	unsigned nbit = i % 8;
	in[nbyte] = in[nbyte] | (1u << nbit);
}

int resheto (int n) {
	char sieve[130] = {0};
	unsigned r = sqrt(1000) + 1;
	unsigned i = 0;
	unsigned j = 0;
	sieve[0] = 0x3;
	for (i = 1; i <= r; ++i) {
		if (check_bit(sieve, i)) {
			continue;
		}
		for (j = i * i; j < 1000; j += i) {
			set_bit(sieve, j);
		}
	}

	for (i = 0; i < 1000; ++i) {
		if (check_bit (sieve ,i) == 0) 
			--n;
		if (n == 0) break;		
	}

	return i;
}
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^


//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

void account_encryption (int N, struct client* bank,  struct client* bank_ciphr, struct key* ciphr) {
	int n = 0, prime_n = 0, second = 0;
	long long id = 0;
	int nums[15] = {0};
	int i = 0;
	int j = 0;
	int num_1 = 0;
	int num_2 = 0;
	int acc = 0;
	int flag = 0;

	for (i = 0; i < N; ++i) {
		id = bank[i].identification_number;
		while (id != 0) {
			num_1 = num_2;
			num_2 = id % 10;
			id = id / 10;

			if (num_1 != 0 && num_2 != 0) {
				n = num_1 + num_2;
			}
		}
		prime_n = resheto (n);
		acc  = bank[i].account;

		while (acc != 0) {
			nums[15 - j] = acc % 10;
			++j;
			acc = acc / 10;
		}

		for (j = 0; j < 15; ++j) {
			if (nums[j] != 0) ++flag;
			if (flag == 2) {
				second = nums[j];
			} 
		}

		ciphr[i].key_1 = prime_n * second;
		bank_ciphr[i].account = ciphr[i].key_1 + bank[i].account;

	}
}

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

