#include <stdio.h>
#include <math.h>

int isPrime(int n) {
    if (n < 1) return 0;
    for (int i = 1; i <= sqrt(n); i++) {
        if ((n% i) == 0) return 0;
    }
    return 1;
}


int isStrong(int n) {
    int fact, i, j, tempNum, sum = 0;
    for (i = n; n > 0; n /= 10) {
        fact = 1;
        tempNum = n % 10;
        for (j = 1; j <= tempNum; j++) {
            fact *= j;
        }
        sum += fact;
    }
    return sum == n ? 1 : 0;
}
