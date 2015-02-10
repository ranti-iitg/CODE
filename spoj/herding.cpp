#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstring>
using namespace std;

vector<string> vs;

int a[1005][1005];
using namespace std;
int n,m;

int check(int u,int b,char c){
if(u>=0&&b>=0&&u<n&&b<m&&a[u][b]==0&&vs[u][b]==c) return true;
else return false;
}

int dfs(int x,int y,int cnt){
    if(x>=0&&y>=0&&x<n&&y<m&&a[x][y]==0){
        a[x][y]=cnt;
        if(vs[x][y]=='N') dfs(x-1,y,cnt);
        else if(vs[x][y]=='S') dfs(x+1,y,cnt);
        else if(vs[x][y]=='E') dfs(x,y+1,cnt);
        else dfs(x,y-1,cnt);

        if(check(x,y+1,'W')) dfs(x,y+1,cnt);
        if(check(x+1,y,'N')) dfs(x+1,y,cnt);
        if(check(x,y-1,'E')) dfs(x,y-1,cnt);
        if(check(x-1,y,'S')) dfs(x-1,y,cnt);
    }
}

int main(){
    cin>>n;
   // cout<<endl<<n<<endl;
    cin>>m;
    //cout<<m<<endl;
    string s;
    getline(cin,s);
    cin.clear();
    for(int i=1;i<=n;++i){
        getline(cin,s);
       // cout<<s<<endl;
        vs.push_back(s);
    }
    memset(a,0,sizeof(a));
    int cnt=0;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(a[i][j]==0) {++cnt;dfs(i,j,cnt);}
        }
    }
    cout<<cnt;
    return 0;
}
