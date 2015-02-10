#include<iostream>
#include<algorithm>
using namespace std;

int t;
int dp[1101];

int main(){
    for(int i=0;i<=1100;++i){
        dp[i]=9999999;
    }
    for(int i=0;i<=32;++i){
        dp[i*i]=1;
    }

    for(int i=2;i<=1000;++i){
        if(dp[i]!=1){
                int mini=dp[i];
                for(int j=i-1;j>=i/2;--j){
                        mini=min(mini,dp[j]+dp[i-j]);

                }
                dp[i]=mini;
        }
    }
cin>>t;
int a;
for(int i=0;i<t;++i){
    cin>>a;
    cout<<dp[a]<<endl;
}

return 0;

}
