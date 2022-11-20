#include <stdio.h>
#include "NumClass.h"

int isPrime(int num)
{
    if (num < 1)
    {
        return 0;
    }
    else
    {
        for (int i = 2; i <= (num/2); i++)
        {
            if (num % i == 0)
            {
                return 0;
            }
        }
        return 1;
    }
}

int isStrong(int num)
{
    int endOfNum, powerSum = 1, numSum = 0, temp = num;
    while (temp != 0)
    {
        endOfNum = temp % 10;
        for (int i = 1; i <= endOfNum; i++)
        {
            powerSum *= i;
        }
        numSum += powerSum;
        powerSum = 1;
        temp /= 10;
    }
    if (num == numSum)
    {
        return 1;
    }
    else return 0;
}