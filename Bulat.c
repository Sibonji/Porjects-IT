#include <stdio.h>
#include <stdlib.h>
#include "head_bank.h"

void code_encryption (int N, struct client *bank, struct client *bank_ciphr, struct key *ciphr)
    {
    int i = 0;
    int key = 0;

    for(i = 0; i < N; i++)
	{
	key = find_code_key(bank, i);

	bank_ciphr[i].key_3 = key;
	}
    }

int find_code_key(struct client *bank, int i)
    {
    int min[3] = {10};
    int max = 10;
    int sum = 0;
    int j = 0;
    int number[10] = {-1};
    int code_num = bank[i];
    long long int key = 0;

    for(j = 0; j < 10; j++)
	{
	number[j] = code_num % 10;

	code_num = (code_num - number[j]) / 10;
	}
     
    j = 9;
    
    max = number[0];

    while()
	{
	if(number[j] != 0) break;
	
	number[j] = -1;

	--j;
	}

    int k;
    int to_del;

    for(k = 0; k < 3; k++)
	{
	for(j = 0; j < 9; j++)
	    {
	    if(number[j] != -1)
	        { 
	        if(min[k] > number[j])
		    {
		    to_del = j;
		    }
		}
	    }

	number[to_del] = -1;
	}

    sum = min[0] + min[1] + min[2];

    if(sum = 0) sum = 27;

    key = combination(sum, max);

    return key;
    }

long long int combination(int n, int m)
    {
    int i = 1;
    int res = 1;

    int n_fac = 0;
    int m_fac = 0;
    int n_m_fac = 0;
    int n_m = 0;

    if((n - m) >= 0) n_m = n - m;
    else n_m = m - n;

    n_fac = find_fac(int n, int i, int res);

    m_fac = find_fac(int m, int i, int res);

    n_m_fac = find_fac(int n_m, int i, int res);

    long long int quant = 0;
    
    if((n - m) >= 0) quant = n_fac / (n_m_fac * m_fac);
    else quant = m_fac / (n_m_fac * n_fac);

    return quant;
    }

int factorial(int n, int i, int res)
    {
    res = res * i;
    ++i;

    if(i <= n)
	{
	find_fac(int n, int i, int res);
	}

    if(i > n) return res;
    }
