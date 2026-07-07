#include <stdio.h>
int main(){
    int n,pos,val;
    scanf("%d",&n);
    int a[n+1];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    scanf("%d%d",&pos,&val);
    for(int i=n;i>pos;i--) a[i]=a[i-1];
    a[pos]=val;
    n++;
    for(int i=0;i<n;i++) printf("%d ",a[i]);
    return 0;
}
