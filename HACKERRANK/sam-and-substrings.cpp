#include<iostream>
#include<cstring>
#include<cstdio>
#define MOD 1000000007
#define MAXL 200005

using namespace std;
long long dp[MAXL];
char str[MAXL];

int main(){
    memset(dp,0,sizeof(dp));
    int j=scanf("%s", str);
    int n = strlen(str);
    dp[0] = str[0] - '0';
    for (int i = 1; i < n; i++) {
    dp[i]= (dp[i]+dp[i-1]*10)%MOD;
    dp[i]=(dp[i]+ (i+1)*(str[i]-'0'))%MOD;
    }

    long long ret = 0;
    for(int i=0;i<n;i++){
    ret=(ret+dp[i])%MOD;
    }
    cout<<ret<<endl;
return 0;}
