#include<iostream>
#include<cstring>

using namespace std;
int N,K;
int A[105][105];
int  mod = 1000000;

int coins(int n, int k) {
    if (k <= 1)
        return 1;
    else if (A[n][k] != -1)
        return A[n][k];
    int i;
    A[n][k] = 0;
    for (i = 0; i <= n; ++i)
        A[n][k] = (A[n][k] + coins(n-i, k - 1)) % 1000000;
    return A[n][k];
}

int main(){
    while(cin>>N>>K&&K){
        memset(A,-1,sizeof(A));
        cout<<coins(N,K)<<endl;
    }


return 0;}
