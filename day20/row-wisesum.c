#include <stdio.h>
int main(){
    int n,m,p,q;
    scanf("%d%d%d%d",&n,&m,&p,&q);
    if(m!=p){printf("Invalid");return 0;}
    int a[n][m],b[p][q],c[n][q];
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf("%d",&a[i][j]);
    for(int i=0;i<p;i++) for(int j=0;j<q;j++) scanf("%d",&b[i][j]);
    for(int i=0;i<n;i++){
        for(int j=0;j<q;j++){
            c[i][j]=0;
            for(int k=0;k<m;k++) c[i][j]+=a[i][k]*b[k][j];
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
    return 0;
}
