#include <stdio.h>
#include <math.h>
int armstrong(int n){
    int temp=n,sum=0,d=(int)log10(n)+1;
    while(temp!=0){
        int r=temp%10;
        sum+=pow(r,d);
        temp/=10;
    }
    return sum==n;
}
int main(){
    int n;
    scanf("%d",&n);
    if(armstrong(n)) printf("Armstrong");
    else printf("Not Armstrong");
    return 0;
}
