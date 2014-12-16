#include<iostream>
#include<algorithm>
using namespace std;

int a[4][25];
int a0[22],a1[22],a2[22];
int solve(int n){
    a[0][0]=a[1][0]=a[2][0]=0;
    for(int i=1;i<=(n+1);++i){
        a[0][i]= min(a[1][i-1]+a1[i-1],a[2][i-1]+a2[i-1]);

        a[1][i]= min(a[0][i-1]+a0[i-1],a[2][i-1]+a2[i-1]);

        a[2][i]= min(a[0][i-1]+a0[i-1],a[1][i-1]+a1[i-1]);
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
    a0[0]=a1[0]=a2[0]=0;
    int n;
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a0[i]>>a1[i]>>a2[i];
    }
    solve(n);
    int j=min(a[0][n+1],a[1][n+1]);
    j=min(j,a[2][n+1]);
    cout<<j<<endl;
    }
return 0;}
