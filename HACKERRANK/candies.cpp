#include<iostream>
using namespace std;

int main(){
    int n;
    int a[100005];
    int left[100005];
    int right[100005];

    cin>>n;//strudents
    for(int i=0;i<n;++i){
        cin>>a[i];
    }

    long long TotalCandies = 0;
    for(int i=0;i<=n;++i){
        left[i]=right[i]=1;
    }
    for(int i=n-2;i>=0;i--){
        if(a[i + 1] < a[i])
        right[i] = 1 + right[i + 1];
    }
    for(int i=1;i<n;i++){
        if(a[i - 1] < a[i])
        left[i]=1+left[i - 1];
    }
    for (int i=0;i<n;i++) {
    TotalCandies+=max(right[i],left[i]);
    }
cout<<TotalCandies;
return 0;}
