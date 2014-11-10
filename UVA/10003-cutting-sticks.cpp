#include<iostream>
#include<cstring>
using namespace std;

int arr[55];//store cuts here
int bcut[55][55];
int N;//number of cuts to be made
int l;//length of rod
int cut(int l,int r){
 if(l+1==r){
     return 0;
 }
 else if (bcut[l][r]!=-1) return bcut[l][r];
 else{
     int mini=10000000;
  for(int i=l+1;i<r;++i){
        mini=min(mini,cut(l,i)+cut(i,r)+arr[r]-arr[l]);
  }
     bcut[l][r]=mini;
     return mini;
 }
}

int main(){
     while(cin>>l&&l){
    arr[0]=0;
    memset(bcut,-1,sizeof(bcut));
    //take input
    cin>>N;
    for(int i=1;i<=N;++i){
        cin>>arr[i];
    }
   arr[N+1]=l;
    cout<<"The minimum cutting is "<<cut(0,N+1)<<"."<<endl;
     }
return 0;}
