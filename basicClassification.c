#include <stdio.h>
#include "NumClass.h"

 
 double sqrt(int number){

    float temp, sqrt;

    sqrt = number / 2;
    temp = 0;

    // Iterate until sqrt is different of temp, that is updated on the loop
    while(sqrt != temp){
        // initially 0, is updated with the initial value of 128
        // (on second iteration = 65)
        // and so on
        temp = sqrt;

        // Then, replace values (256 / 128 + 128 ) / 2 = 65
        // (on second iteration 34.46923076923077)
        // and so on
        sqrt = ( number/temp + temp) / 2;
    }
    return sqrt;

 }

int isPrime(int num)
{
    if (num < 1)
    {
        return 0;
    }
    else
    {
        for (int i = 2; i <= sqrt(num); i++)
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
    if (num==0){
        return 0;
    }
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