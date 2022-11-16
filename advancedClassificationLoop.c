

#include <stdio.h>

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