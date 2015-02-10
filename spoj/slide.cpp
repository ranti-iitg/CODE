#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int n,m;
long long dp[10005][12][12];
int g[10005][12];
int main(){
    cin>>n;
    cin>>m;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            cin>>g[i][j];
        }
    }

    for(int i=1;i<=m;++i){
        for(int j=1;j<=m;++j){
            dp[1][i][j]=-99999999;
        }
    }
    for(int l=1;l<=n;++l){
        for(int i=0;i<=(m+1);++i){
            dp[l][0][i]=dp[l][i][0]=-99999999;
        }
        for(int i=0;i<=(m+1);++i){
            dp[l][m+1][i]=dp[l][i][m+1]=-99999999;
        }
    }

    dp[1][1][m]=g[1][1]+g[1][m];

    for(int l=2;l<=n;++l){
        for(int i=1;i<=m;++i){
            for(int j=1;j<=m;++j){
                dp[l][i][j]=dp[l-1][i][j];
                dp[l][i][j]=max(dp[l][i][j],dp[l-1][i][j-1]);
                dp[l][i][j]=max(dp[l][i][j],dp[l-1][i][j+1]);
                dp[l][i][j]=max(dp[l][i][j],dp[l-1][i+1][j-1]);
                dp[l][i][j]=max(dp[l][i][j],dp[l-1][i+1][j]);
                dp[l][i][j]=max(dp[l][i][j],dp[l-1][i+1][j+1]);
                dp[l][i][j]=max(dp[l][i][j],dp[l-1][i-1][j-1]);
                dp[l][i][j]=max(dp[l][i][j],dp[l-1][i-1][j]);
                dp[l][i][j]=max(dp[l][i][j],dp[l-1][i-1][j+1]);
                if(i!=j)
                    dp[l][i][j]=dp[l][i][j]+g[l][i]+g[l][j];
                else
                    dp[l][i][j]=dp[l][i][j]+g[l][i];


            }
        }
    }
    cout<<dp[n][1][m];
}
