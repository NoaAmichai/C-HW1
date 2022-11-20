#include <stdio.h>
#include "NumClass.h"

int power(int num ,int exp){
    int sum=1;
    for (int i=0;i<exp;i++){
        sum*=num;
    }
    return sum;
}

int NumLen(int n)
{
    int counter = 0;
    int temp = n;
    while (temp > 0)
    {
        temp = temp / 10;
        counter++;
    }
    return counter;
}

int PalindromeRec(int num, int size)
{
    if (size == 0 || size == 1)
    {
        return 1;
    }
    int numOfZeros = power(10, size - 1);
    if ((num / numOfZeros) == (num % 10))
    {
        return PalindromeRec(((num % numOfZeros) / 10), size - 2);
    }
    else
    {
        return 0;
    }

}

// Olen=Original length
int ArmRec(int num, int len, int Olen)
{
    if (len == 0)
    {
        return 0;
    }
    return ArmRec(num / 10, len - 1, Olen) + power(num % 10, Olen);
}

int isArmstrong(int num)
{
    int len;
    len = NumLen(num);
    return (ArmRec(num, len, len) == num) ? 1 : 0;

}

int isPalindrome(int num)
{
    int len;
    len = NumLen(num);
    return PalindromeRec(num, len);
}

