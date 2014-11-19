#include<iostream>
#include<algorithm>
using namespace std;
int a[50005];
long long profit=0;

int main(){
int t;
int n;
cin>>t;
while(t--){
cin>>n;
profit=0;
for (int i=0; i<n; ++i)
    cin>>a[i];

int maxi = 0;
for (int i=n-1; i>=0; --i) {
    maxi = max(maxi, a[i]);
    profit += (long long)maxi - a[i];
}
cout<<profit<<endl;
}
return 0;
}
