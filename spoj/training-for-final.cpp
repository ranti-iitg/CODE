#include<iostream>
#include<algorithm>

using namespace std;
int dp[25][25];
int x,y;
int p;
int solve(int n,int m){
     p=dp[x][y];
for(int i=n;i>0;--i){
    for(int j=m;j>0;--j){
        if(i==x&&j==y) return 0;
        int a=999999;
        if(j+1<=m) a=dp[i][j+1];
        int b=999999;
        if(i+1<=n) b=dp[i+1][j];
        int c=min(a,b);
        if(c==999999) c=0;
        dp[i][j]=c+dp[i][j];
    }
}

}

int main(){
int n,m;
cin>>n>>m;

cin>>x>>y;

for(int i=1;i<=n;++i){
    for(int j=1;j<=m;++j){
        cin>>dp[i][j];
    }
}
solve(n,m);
int a=999999;
if(y+1<=m) a=dp[x][y+1];
int b=999999;
if(x+1<=n) b=dp[x+1][y];
int c=min(a,b);
if(c==999999) c=0;
if(p>=c)
    cout<<"Y "<<p-c<<endl;
else
    cout<<"N"<<endl;
return 0;}
