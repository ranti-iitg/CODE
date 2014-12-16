#include<iostream>
#include<algorithm>
using namespace std;
int dp[1001][51];
int a[51];//weight of each bag
int b[51];//price of each bag
int solve(int k,int m){

for(int i=0;i<=m;++i){
    dp[0][i]=0;
}
for(int j=0;j<=k;++j){
    dp[j][0]=0;
}

for(int i=1;i<=m;++i){
    for(int j=1;j<=k;++j){
        if(a[i]<=j)
            dp[j][i]=max((dp[j][i-1]),(dp[j-a[i]][i-1]+b[i]));
        else
            dp[j][i]=dp[j][i-1];

    }
}
}


int main(){
    int t;
    cin>>t;
    while(t--){
        int k,m;
        cin>>k>>m;
        for(int i=1;i<=m;++i){
            cin>>a[i]>>b[i];
        }
        solve(k,m);
        cout<<"Hey stupid robber, you can get "<<dp[k][m]<<"."<<endl;
    }
return 0;}
