#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int dp[501][101];
int price[101];
int fun[101];
int budget;
int n;

int main(){

    while(1){
    cin>>budget;
    cin>>n;
    if(budget==0&&n==0) break;
    for(int i=1;i<=n;++i){
    cin>>price[i];
    cin>>fun[i];
    }

    for(int i=0;i<102;++i)
        dp[0][i]=0;
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;++i){
        for(int m=1;m<=budget;++m){
            if(price[i]<=m)
                dp[m][i]=max((dp[m-price[i]][i-1]+fun[i]),(dp[m][i-1]));
            else
                dp[m][i]=dp[m][i-1];
        }
    }
    int k=budget;
    while(k>=0&&dp[k][n]==dp[budget][n]){
        --k;
    }
    if(dp[k][n]!=dp[budget][n]) ++k;
    cout<<k<<" "<<dp[budget][n]<<endl;
    }
return 0;}
