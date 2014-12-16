#include<iostream>
#include<algorithm>
using namespace std;

int dp[1005][1005];
int a[1005];
//n number of bushes
//k at max number of berries
int solve(int n,int k){
    for(int i=0;i<=n;++i){
        dp[0][i]=0;
    }
    for(int i=0;i<=k;++i){
        dp[i][0]=0;
    }
    for(int j=1;j<=k;++j){
        if(a[1]<=j){
            dp[j][1]=a[1];
        }
        else
        dp[j][1]=dp[j][0];
    }
    for(int i=2;i<=n;++i){
        for(int j=1;j<=k;++j){
            if(a[i]<=j){
                dp[j][i]=max(dp[j][i-1],dp[j-a[i]][i-2]+a[i]);
            }
            else
            dp[j][i]=dp[j][i-1];
        }
    }
}
int main(){
    int t;
    cin>>t;
    for(int l=1;l<=t;++l){
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    solve(n,k);
    cout<<"Scenario #"<<l<<": "<<dp[k][n]<<endl;
    }
return 0;}
