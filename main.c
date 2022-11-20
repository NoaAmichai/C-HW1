#include <stdio.h>
#include "NumClass.h"

int main()
{
    int firstNum, secondNum;
    scanf("%d", &firstNum);
    scanf("%d", &secondNum);
    printf("The Armstrong numbers are:");
    for (int i = firstNum; i <= secondNum; i++)
    {
        if (isArmstrong(i))
        {
            printf(" %d", i);
        }
    }
    printf("\nThe Palindrome are:");
    for (int i = firstNum; i <= secondNum; i++)
    {
        if (isPalindrome(i))
        {
            printf(" %d", i);
        }
    }
    printf("\nThe Prime numbers are:");
    for (int i = firstNum; i <= secondNum; i++)
    {
        if (isPrime(i))
        {
            printf(" %d", i);
        }
    }

    printf("\nThe Strong numbers are:");
    for (int i = firstNum; i <= secondNum; i++)
    {
        if (isStrong(i))
        {
            printf(" %d", i);
        }
    }

    return 0;
}
