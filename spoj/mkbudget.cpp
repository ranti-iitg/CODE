#include<iostream>
using namespace std;
int opt[25][31];
int max_a=30;
int sal,fire,hire,n;
int A[25];
int solve(){
    for (int i = 0; i < A[0]; ++i)
        opt[0][i] = 1000000000;
    for(int i = A[0]; i <= max_a; i++)  //for 1st month
        opt[0][i] = i*(hire + sal);

    for(int i = 1; i < n; i++)
        for(int j = 0; j <= max_a; j++){
                opt[i][j] = 1000000000;
                if (A[i] > j) continue;
                for(int k = 0; k <= max_a; k++)
                    opt[i][j] = min(opt[i][j],
                       opt[i-1][k] + j*sal + (j>k ? (j-k)*hire : (k-j)*fire));
            }

    int sol=opt[n-1][0];
    for(int j=0;j<=max_a;++j) sol=min(sol,opt[n-1][j]);
    return sol;
}

int main(){
    int turn=0;
    while(cin>>n&&n){
            cin>>hire;
            cin>>sal;
            cin>>fire;
        for(int i=0;i<n;++i) cin>>A[i];
        ++turn;
        cout<<"Case "<<turn<<", cost = $"<<solve()<<endl;

    }
return 0;}
