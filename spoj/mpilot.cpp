#include<iostream>
#include<algorithm>
#include<cstring>
int MAXM =1<<30;
using namespace std;

int dp[10005][10005];
int a[10005];
int b[10005];

int bottom_up(int n){
for(int i=1;i<=n;++i){
    for(int j=0;j<=i;++j){
        dp[i][j]=MAXM;
        if(j-1>=0)
            dp[i][j]=min(dp[i][j],dp[i-1][j-1]+a[i]);
        if(j+1<=i)
            dp[i][j]=min(dp[i][j],dp[i-1][j+1]+b[i]);
    }

}
return dp[n][0];
}

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>b[i]>>a[i];
    }
    dp[0][0]=0;
    cout<<bottom_up(n);
return 0;}
