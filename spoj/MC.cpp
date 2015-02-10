#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

int ls,lt;
int dp[1005][1005];
string s,t;
int solve(){
    dp[0][0]=0;
    for(int i=1;i<=ls;++i){
        dp[i][0]=15*i;
    }
    for(int j=1;j<=lt;++j){
        dp[0][j]=30*j;
    }

    for(int i=1;i<=ls;++i){
        for(int j=1;j<=lt;++j){
            dp[i][j]=dp[i][j-1]+30;
            dp[i][j]=min(dp[i][j],dp[i-1][j]+15);
            if(s[i-1]==t[j-1])
                dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
        }
    }
    return dp[ls][lt];

return 0;}

int main(){
   while(1){
    s.clear();t.clear();
    getline(cin,s);
    if(s[0]=='#') break;

    getline(cin,t);
    ls=s.size();
    lt=t.size();
    memset(dp,-1,sizeof(dp));
    cout<<solve()<<endl;
   }
return 0;
}
