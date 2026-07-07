#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    int temp=a[0];
    for(int i=1;i<n;i++) a[i-1]=a[i];
    a[n-1]=temp;
    for(int i=0;i<n;i++) printf("%d ",a[i]);
    return 0;
}
