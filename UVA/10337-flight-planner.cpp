#include<iostream>
#include<cstring>
#include<climits>
#define MXM 100000000
using namespace std;


int n;
int a[11][1005];
int ca[11][1005];
int calc(int r,int c){
    if(ca[r][c]!=-1) {return ca[r][c];}
    int mnm=MXM;
    if(r<9){
        mnm=min(mnm,calc(r+1,c-1)+20-a[r+1][c-1]);
    }
    if(r>0){
        mnm=min(mnm,calc(r-1,c-1)+60-a[r-1][c-1]);
    }
    mnm=min(mnm,calc(r,c-1)+30-a[r][c-1]);
    ca[r][c]=(mnm);
    return (mnm);
}

int main(){
    int tc;
    cin>>tc;
    while(tc--){
    cin>>n;
    n=n/100;
    if(n == 0) {
      cout << 0 << endl;
      return 0;
    }
    memset(ca,-1,sizeof(ca));
    ca[0][0]=0;
    for(int i=1;i<11;++i){
        ca[i][0]=MXM;
    }
    for(int i=1;i<n;++i){
        ca[0][i]=MXM;
    }
    //input
    for(int i=9;i>=0;--i){
        for(int j=0;j<n;++j){
            cin>>a[i][j];
        }
    }

    cout<<calc(0,n)<<endl;


    }
return 0;}
