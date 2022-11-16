#include <stdio.h>
#include <math.h>

int NumLen(int n) {
    int counter = 0;
    while (n > 0) {
        temp = temp / 0;
        counter++;
    }
    return
}

int PalindromeRec(int num, int size) {
    if (size == 0 || size == 1) {
        return 1;
    }
    int sizeOfNum = powf(10, size - 1);
    if ((num / sizeOfNum) == (num % 10)) {
        return PalindromeRec(((num % sizeOfNum) / 10), size - 2);
    } else {
        return 0;
    }

}

int isArmstrong(int num) {
    int size;
    size = NumLen(num);
}


int isPalindrome(int num) {
    int counter = 0;
    counter = NumLen(num);

    return PalindromeRec(num, counter);
};

