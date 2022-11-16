#include <stdio.h>

int isArmstrong(int n) {
    //String str = Integer.toString(n);
    //int len = str.length();
    int i, sum = 0;
    while (n > 0) {
        //sum += pow(n % 10, len);
        n /= 10;
    }
    return sum == n ? 1 : 0;
}


int isPalindrome(int n) {
	
	
	
	
}

