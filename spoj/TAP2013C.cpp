#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


int n,s;

int main(){
    cin>>n;
    cin>>s;
    int a,b;
    vector< vector<int> > vvi(n+1);
    for(int i=1;i<=s;++i){
        cin>>a;
        cin>>b;
        vvi[a].push_back(b);
    }

    long long nu[n+1];
    long long nu2[n+1];
    nu[n]=1;
    for(int i=n-1;i>0;--i){
        long long sum=0;
        for(int j=0;j<(int)vvi[i].size();++j){
            int to=vvi[i][j];
            sum=sum+nu[to];
        }
        nu[i]=sum;
    }

//now largest sum path
    nu2[n]=1;
    for(int i=n-1;i>=1;--i){
        long long temp=0;
        for(int j=0;j<(int)vvi[i].size();++j){
            int to=vvi[i][j];
            temp=max(temp,nu[i]+nu2[to]);
        }
        nu2[i]=temp;
    }

cout<<nu2[1];



}
