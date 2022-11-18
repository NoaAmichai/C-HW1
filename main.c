#include <stdio.h>
#include "NumClaas.h"
#include <math.h>

int main()
{
    int firstNum, secondNum;
    scanf("%d%d", &firstNum, &secondNum);
    for (int i = firstNum; i <= secondNum; i++)
    {
        if (isPrime(i))
        {
            printf("%d ", i);
        }
    }

    for (int i = firstNum; i <= secondNum; i++)
    {
        if (isArmstrong(i))
        {
            printf("%d ", i);
        }
    }

    for (int i = firstNum; i <= secondNum; i++)
    {
        if (isStrong(i))
        {
            printf("%d ", i);
        }
    }

    for (int i = firstNum; i <= secondNum; i++)
    {
        if (isPalindrome(i))
        {
            printf("%d ", i);
        }
    }

    return 0;
}
