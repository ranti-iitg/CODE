#include<iostream>
#include<algorithm>
#include<cstring>
#define MAXM 100000007
using namespace std;

int t,n,m;
int dp[205][205];
int a[205];
int b[205];
//dp[i][j]  i=fox  j=money
int solve(){
for(int i=1;i<=m;++i){
    if(i>=a[1]&&i<=b[1])dp[1][i]=1;
    else dp[1][i]=0;
}

for(int i=2;i<=n;++i){
    for(int j=1;j<=m;++j){
        for(int k=a[i];k<=b[i]&&k<j;++k){
            dp[i][j]=(dp[i][j]+dp[i-1][j-k])%MAXM;
        }
    }
}
return dp[n][m];
}

int main(){
cin>>t;
while(t--){
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i]>>b[i];
    }
    memset(dp,0,sizeof(dp));
    cout<<solve()%MAXM<<endl;
}
}
