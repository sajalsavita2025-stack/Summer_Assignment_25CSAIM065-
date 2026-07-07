#include <stdio.h>
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int a[n][m];
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf("%d",&a[i][j]);
    int maxCol=0,sumCol=0;
    for(int i=0;i<n;i++) sumCol+=a[i][0];
    for(int j=1;j<m;j++){
        int sum=0;
        for(int i=0;i<n;i++) sum+=a[i][j];
        if(sum>sumCol){sumCol=sum;maxCol=j;}
    }
    printf("%d",maxCol);
    return 0;
}
