#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    int first,second;
    if(a[0]>a[1]){first=a[0];second=a[1];}
    else{first=a[1];second=a[0];}
    for(int i=2;i<n;i++){
        if(a[i]>first){second=first;first=a[i];}
        else if(a[i]>second && a[i]!=first) second=a[i];
    }
    printf("%d",second);
    return 0;
}
