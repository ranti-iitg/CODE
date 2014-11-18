#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int a[50];

int main(){
    a[0]=1;
    a[1]=1;
    a[2]=1;
    a[3]=1;
    for(int i=4;i<41;++i){
        a[i]=a[i-1]+a[i-4];
    }
    //cout<<a[40]; 217286
    //prime number logic;
    bool b[217290];
    for(int i=0;i<217290;++i) b[i]=1;
    b[0]=b[1]=0;//composite
    for(int i=4;i<217290;i=i+2){
        b[i]=0;
    }
     for(int i=3;i<=sqrt(217290);i+=2){
        for(int j=i;j*i<217290;j++)
            b[i*j]=0;
    }
    int c[217290];
    memset(c,0,sizeof(c));
    for(int i=1;i<217290;++i){
        c[i]=c[i-1];
        if(b[i]) ++c[i];
    }
    int t;
    int n;
    cin>>t;
    while(t--){
        cin>>n;
        cout<<c[a[n]]<<endl;
    }

return 0;}
