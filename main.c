#include <stdio.h>
#include "NumClass.h"

int main()
{
    int firstNum, secondNum;
    scanf("%d %d", &firstNum,&secondNum);
    for (int i = firstNum; i <= secondNum; i++)
    {
        if (isPrime(i))
        {
            printf("%d ", i);
        }
    }printf("\n");

    for (int i = firstNum; i <= secondNum; i++)
    {
        if (isArmstrong(i))
        {
            printf("%d ", i);
        }
    }printf("\n");

    for (int i = firstNum; i <= secondNum; i++)
    {
        if (isStrong(i))
        {
            printf("%d ", i);
        }
    }printf("\n");

    for (int i = firstNum; i <= secondNum; i++)
    {
        if (isPalindrome(i))
        {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}
