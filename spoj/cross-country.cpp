#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int a[2005];
int b[2005];
int dp[2005][2005];

int solve(int a_i,int b_i){
memset(dp,0,sizeof(dp));
for(int i=1;i<=a_i;++i){
    for(int j=1;j<=b_i;++j){
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            if(a[i]==b[j])
            dp[i][j]=max(dp[i][j],(dp[i-1][j-1]+1));
    }
}
return dp[a_i][b_i];
}

int main(){
    int d;//number of datasets
    cin>>d;
    while(d--){
    int max_d=0;

        int k;
        int a_i,b_i,i;
        for( i=1;cin>>k,k!=0;++i){
            a[i]=k;
        }
        a_i=i-1;
        while(1){
            for( i=1;cin>>k,k!=0;++i){
                b[i]=k;
            }
            b_i=i-1;
            if(b_i!=0)
            {

            max_d=max(max_d,solve(a_i,b_i));
            }
            else break;
        }
    cout<<max_d<<endl;
    }
    return 0;
}
