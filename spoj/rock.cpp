#include <cstdio>
#include <cstring>
#include <algorithm>
#include<iostream>
#include<string>
using namespace std;
int dp[205];
int n;
string a;

int solve(){
    dp[0]=0;
    if(a[0]=='1') dp[1]=1;
    else dp[1]=0;
for(int i=2;i<=n;++i){
    int zc,oc;
    zc=oc=0;dp[i]=dp[i-1];
    for(int j=i;j>=1;--j){
        if(a[j-1]=='1') ++oc;
        else ++zc;
        if(oc>zc) dp[i]=max(dp[i],dp[j-1]+i-j+1);
    }
}
return dp[n];
}




int main(){
int t;
cin>>t;
while(t--){
cin>>n;
cin>>a;

cout<<solve()<<endl;
}
return 0;
}
