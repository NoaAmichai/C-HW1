#include <stdio.h>
#include "NumClass.h"


int power(int num ,int exp){
    int sum=1;
    for (int i=0;i<exp;i++){
        sum*=num;
    }
    return sum;
}
int isArmstrong(int n)
{
    int sum = 0, temp = n, countLen = 0;
    while (temp > 0)
    { // count the length of n
        countLen++;
        temp /= 10;
    }
    temp = n;
    while (temp > 0)
    {
        sum += power(temp % 10, countLen);
        temp /= 10;
    }
    return sum == n ? 1 : 0;
}

int isPalindrome(int num)
{
    int temp = num, numSum = 0;

    while (temp != 0)
    {
        numSum = numSum * 10;
        numSum += temp % 10;
        temp = temp / 10;
    }
    if (numSum == num)
    {
        return 1;
    }
    return 0;

    
}
