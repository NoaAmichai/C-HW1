#include <stdio.h>
#include <math.h>
#include "NumClaas.h"
int isPrime(int num) {
    if (num < 1) { return 0; }
    for (int i = 1; i < sqrt(num); i++) {
        if (num % i == 0) {
            return 1;
        }
    }
    return 0;
}

int isStrong(int num) {
    int endOfNum, powerSum = 1, numSum = 0, temp = num;
    while (temp != 0) {
        endOfNum = temp % 10;
        for (int i = 1; i <= endOfNum; i++) {
            powerSum = powerSum * i;
        }
        numSum += powerSum;
        powerSum = 1;
        temp = temp / 10;
    }
    if (num == numSum) {
        return 1;
    }
    return 0;
}