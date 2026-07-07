#include <stdio.h>
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int a[n][m];
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf("%d",&a[i][j]);
    int maxRow=0,sumRow=0;
    for(int j=0;j<m;j++) sumRow+=a[0][j];
    for(int i=1;i<n;i++){
        int sum=0;
        for(int j=0;j<m;j++) sum+=a[i][j];
        if(sum>sumRow){sumRow=sum;maxRow=i;}
    }
    printf("%d",maxRow);
    return 0;
}
