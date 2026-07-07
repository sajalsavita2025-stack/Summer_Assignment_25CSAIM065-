#include <stdio.h>
int palindrome(int n){
    int rev=0,temp=n;
    while(temp!=0){rev=rev*10+temp%10;temp/=10;}
    return rev==n;
}
int main(){
    int n;
    scanf("%d",&n);
    if(palindrome(n)) printf("Palindrome");
    else printf("Not Palindrome");
    return 0;
}
