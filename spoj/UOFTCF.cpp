#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;

bool g[55][55];
int p[55][55][55];

int n,m;
bool travel(int l,int i,int j){
return(i!=j&&g[l][i]&&g[l][j]);
}
int t;
int main(){
cin>>t;
while(t--){
cin>>n;
cin>>m;
string s;
getline(cin,s);
cin.clear();
memset(g,0,sizeof(g));
for(int i=1;i<=n;++i){
    getline(cin,s);
    for(int j=0;j<m;++j){
        if(s[j]=='.') g[i][j+1]=1;
        else g[i][j+1]=0;
    }
}
cin.clear();
memset(p,-1,sizeof(p));

for(int i=1;i<=m;++i){
    for(int j=1;j<=m;++j){
        if(i!=j&&g[1][i]&&g[1][j]){
            if(j==i+1||i==j+1){
                p[1][i][j]=1;
            }
            else p[1][i][j]=0;
        }
    }
}

for(int l=1;l<n;++l){
    for(int i=1;i<=m;++i){
        for(int j=1;j<=m;++j){
            if(i!=j&&p[l][i][j]!=-1){
                int a,b;
                a=i;b=j;
                if(travel(l+1,a,b)){
                    if(a==b+1||b==a+1)
                        p[l+1][a][b]=max(p[l+1][a][b],p[l][i][j]+1);
                    else
                        p[l+1][a][b]=max(p[l+1][a][b],p[l][i][j]);
                }
                 a=i;b=j-1;
                if(travel(l+1,a,b)){
                    if(a==b+1||b==a+1)
                        p[l+1][a][b]=max(p[l+1][a][b],p[l][i][j]+1);
                    else
                        p[l+1][a][b]=max(p[l+1][a][b],p[l][i][j]);
                }
                 a=i;b=j+1;
                if(travel(l+1,a,b)){
                    if(a==b+1||b==a+1)
                        p[l+1][a][b]=max(p[l+1][a][b],p[l][i][j]+1);
                    else
                        p[l+1][a][b]=max(p[l+1][a][b],p[l][i][j]);
                }
                 a=i-1;b=j;
                if(travel(l+1,a,b)){
                    if(a==b+1||b==a+1)
                        p[l+1][a][b]=max(p[l+1][a][b],p[l][i][j]+1);
                    else
                        p[l+1][a][b]=max(p[l+1][a][b],p[l][i][j]);
                }
                 a=i+1;b=j;
                if(travel(l+1,a,b)){
                    if(a==b+1||b==a+1)
                        p[l+1][a][b]=max(p[l+1][a][b],p[l][i][j]+1);
                    else
                        p[l+1][a][b]=max(p[l+1][a][b],p[l][i][j]);
                }
                 a=i-1;b=j-1;
                if(travel(l+1,a,b)){
                    if(a==b+1||b==a+1)
                        p[l+1][a][b]=max(p[l+1][a][b],p[l][i][j]+1);
                    else
                        p[l+1][a][b]=max(p[l+1][a][b],p[l][i][j]);
                }
                 a=i+1;b=j+1;
                if(travel(l+1,a,b)){
                    if(a==b+1||b==a+1)
                        p[l+1][a][b]=max(p[l+1][a][b],p[l][i][j]+1);
                    else
                        p[l+1][a][b]=max(p[l+1][a][b],p[l][i][j]);
                }
                 a=i-1;b=j+1;
                if(travel(l+1,a,b)){
                    if(a==b+1||b==a+1)
                        p[l+1][a][b]=max(p[l+1][a][b],p[l][i][j]+1);
                    else
                        p[l+1][a][b]=max(p[l+1][a][b],p[l][i][j]);
                }
                 a=i+1;b=j-1;
                if(travel(l+1,a,b)){
                    if(a==b+1||b==a+1)
                        p[l+1][a][b]=max(p[l+1][a][b],p[l][i][j]+1);
                    else
                        p[l+1][a][b]=max(p[l+1][a][b],p[l][i][j]);
                }
            }

        }
    }
}

int maxi=-1;
for(int i=1;i<=m;++i){
    for(int j=1;j<=m;++j){
            if(i!=j)
            maxi=max(maxi,p[n][i][j]);
    }
}

if(maxi!=-1) cout<<maxi<<endl;
else cout<<"Detour"<<endl;
}
return 0;
}
