#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    int b[n],k=0;
    for(int i=0;i<n;i++){
        int flag=0;
        for(int j=0;j<k;j++) if(a[i]==b[j]){flag=1;break;}
        if(!flag) b[k++]=a[i];
    }
    for(int i=0;i<k;i++) printf("%d ",b[i]);
    return 0;
}
