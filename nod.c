#include <stdio.h>
#include <stdlib.h>
#include "head_bank.h"

int nod (int n, int n1)
{
    int max = n;
    int min = n1;
    if (n1 > n)
    {
        max = n1;
        min = n;
    }

    while (((max - min) > 0) || (min == 1))
    {
        max = max - min;

        if (min > max)
        {
            // swiping variables min and max
            min = min + max;
            max = min - max;
            min = min - max;
        }
    }

    return min;
}
