#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int a[22][22];//a[i]  price
int b[22][22];//b[i] power
int dp[1005][22];
int seal[22];

int buy(int k,int i,int rw){
if(k==0||i==0) return 0;
else if(dp[k][i]!=-1) return dp[k][i];
else {
        int maxi=-99999;
    for(int j=0;a[rw][i]*j<=k;++j){
        maxi=max(maxi,b[rw][i]*j+buy(k-a[rw][i]*j,i-1,rw));
    }
    dp[k][i]=maxi;
    return maxi;
}
}


int main(){
    int t;
    cin>>t;
    while(t--){
    int n,m,k;
    cin>>n>>m>>k;//k money  m type of weapon n number of batches
    for(int i=1;i<=n;++i){
        cin>>seal[i];
    }
    for(int j=1;j<=n;++j){
    for(int i=1;i<=m;++i){
        cin>>a[j][i];//price
    }}
    for(int j=1;j<=n;++j){
    for(int i=1;i<=m;++i){
        cin>>b[j][i];//power
    }}
    int maxi=0;
    for(int rw=1;rw<=n;++rw){
        memset(dp,-1,sizeof(dp));
       maxi=max(maxi,buy(k-seal[rw],m,rw));
    }
    cout<<maxi<<endl;
    }
return 0;}
