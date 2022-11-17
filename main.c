#include <stdio.h>
#include "NumClaas.h"
#include <math.h>

int main() {

    int firstNum, secondNum, big, small;
    scanf("%d%d", &firstNum, &secondNum);
    big = fmax(firstNum, secondNum);
    small = fmin(firstNum, secondNum);

    for (int i = small; i <= big; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }

    for (int i = small; i <= big; i++) {
        if (isArmstrong(i)) {
            printf("%d ", i);
        }
    }

    for (int i = small; i <= big; i++) {
        if (isStrong(i)) {
            printf("%d ", i);
        }
    }

    for (int i = small; i <= big; i++) {
        if (isPalindrome(i)) {
            printf("%d ", i);
        }
    }

    return 0;
}
