#include <stdio.h>
#include <math.h>
#include "NumClaas.h"
int NumLen(int n) {
    int counter = 0;
    while (n > 0) {
        temp = temp / 10;
        counter++;
    }
    return counter;
}

int PalindromeRec(int num, int size) {
    if (size == 0 || size == 1) {
        return 1;
    }
    int numOfZeros = powf(10, size - 1);
    if ((num / numOfZeros) == (num % 10)) {
        return PalindromeRec(((num % numOfZeros) / 10), size - 2);
    } else {
        return 0;
    }

}
//Olen=Original length
int ArmRec(int num, int len, int Olen) {
    if (len == 0) {
        return 0;
    }
    return ArmRec(num / 10, len - 1,Olen) + powf(num % 10, Olen);
}

int isArmstrong(int num) {
    int len;
    len = NumLen(num);
    return (ArmRec(num, len, len) == num) ? 1 : 0;

}


int isPalindrome(int num) {
    int len;
    len = NumLen(num);
    return PalindromeRec(num, len);
}

