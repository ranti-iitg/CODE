#include<iostream>
#include<cstring>
using namespace std;

int a[10005];

int main(){
int m,n,t;
memset(a,0,sizeof(a));
while(cin>>m>>n>>t){
    memset(a,0,sizeof(a));
    a[m]=1;
    a[n]=1;
    for(int i=min(m,n)+1;i<=t;++i){
        if((i-m)>=0&&a[i-m])a[i]=max(a[i],a[i-m]+1);
        if((i-n)>=0&&a[i-n])a[i]=max(a[i],a[i-n]+1);
    }
    int k=t;
    while(a[k]==0&&k>0){--k;}
    if(t-k){
        cout<<a[k]<<" "<<t-k<<endl;
    }
    else{
        cout<<a[t]<<endl;
    }
}
return 0;}
