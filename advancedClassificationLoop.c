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



isPalindrome(int num){
    int temp=num,numSum=0;

    while (temp!=0){
        numSum=numSum*10;
        numSum+=temp%10;
        temp=temp/10;
    }
    if(numSum==num){
        return 1;
    }
    return 0;


}
