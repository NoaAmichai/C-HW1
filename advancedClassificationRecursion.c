#include <stdio.h>
#include <math.h>

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

int isArmstrong(int num) {
    int size,temp=num,sum=0;
    size = NumLen(num);
    while (temp>0){
        sum+=powf(temp%10);
        temp=temp/10;
    }
    if(num==sum){
        return 1;
    }else{
        return 0;
    }
}


int isPalindrome(int num) {
    int len = 0;
    len = NumLen(num);

    return PalindromeRec(num, len);
}

