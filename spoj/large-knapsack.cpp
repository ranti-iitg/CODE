#include<stdio.h>
#define max(x,y) (x>y)?x:y;

int dp[3][2000005];
int a[505];//weight of each bag
int b[505];//price of each bag
int solve(int k,int m){
int i,j;
for( i=0;i<=m;++i){
    dp[i][0]=0;
}
for(j=0;j<=k;++j){
    dp[0][j]=0;
}

for( i=1;i<=m;++i){
    if(i%2){
        for( j=1;j<=k;++j){
            if(a[i]<=j)
              {

                dp[1][j]=max((dp[0][j]),(dp[0][j-a[i]]+b[i]));
              }
            else
                dp[1][j]=dp[0][j];

        }
    }
    else{
        for( j=1;j<=k;++j){
        if(a[i]<=j)
              {

                dp[0][j]=max((dp[1][j]),(dp[1][j-a[i]]+b[i]));
              }
            else
                dp[0][j]=dp[1][j];

        }
    }

}
return 0;
}


int main(){

        int k,m,i,j;
        scanf("%d%d",&k,&m);
        for( i=1;i<=m;++i){
                scanf("%d%d",&b[i],&a[i]);
        }
        solve(k,m);
        if(m%2)
               printf("%d\n",dp[1][k]);
        else
               printf("%d\n",dp[0][k]);
return 0;}
