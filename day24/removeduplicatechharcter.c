#include <stdio.h>
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int a[n][m];
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf("%d",&a[i][j]);
    int sum=0;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(i==0||j==0||i==n-1||j==m-1) sum+=a[i][j];
    printf("%d",sum);
    return 0;
}
