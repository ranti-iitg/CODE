#include<iostream>
#include<algorithm>

using namespace std;

int main(){

int n;
cin>>n;
int a[n+1][2];
int dp[n+1][2];
for(int i=0;i<n;++i){
    cin>>a[i][0]>>a[i][1];
}
dp[0][0]=a[0][1];dp[0][1]=a[0][0];
for(int j=1;j<n;++j){
    dp[j][0]=a[j][1]+max((dp[j-1][0]+abs(a[j-1][0]-a[j][0])),(dp[j-1][1]+abs(a[j-1][1]-a[j][0])));
    dp[j][1]=a[j][0]+max((dp[j-1][1]+abs(a[j-1][1]-a[j][1])),(dp[j-1][0]+abs(a[j-1][0]-a[j][1])));
}
cout<<max(dp[n-1][0],dp[n-1][1])<<endl;
return 0;}
