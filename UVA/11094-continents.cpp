#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<utility>
#include<cstring>
using namespace std;

int dr[] ={1,0,-1,0};
int dc[] ={0,1,0,-1};
bool a[21][21];
char b[21][21];
int M,N;
int p,q;
int bfs(int i,int j){
    int ret=0;
    pair <int,int> foo;
    queue< pair < int,int > > q;
    q.push(pair<int,int>(i,j));a[i][j]=0;++ret;
    while(!q.empty()){
        foo=q.front();
        q.pop();
        int r,c;
        for(int d=0;d<4;++d){
            r=foo.first+dr[d];
            c=foo.second+dc[d];
            c=c+N;
            c=c%N;
            if(r>=0&&r<M&&c>=0&&c<N&&a[r][c]){
                a[r][c]=0;++ret;
                q.push(pair<int,int>(r,c));
            }
        }
    }
return ret;
}
int main(){
    while(cin>>M){
    cin>>N;cin.ignore();
    string s;
    memset(a,0,sizeof(a));
    for(int i=0;i<M;++i){
        cin>>s;
        for(int j=0;j<N;++j){
            b[i][j]=s[j];
        }
    }

    //king standing;
    cin>>p;
    cin>>q;
    for(int i=0;i<M;++i){
        for(int j=0;j<N;++j){
            if(b[p][q]==b[i][j])a[i][j]=1;
        }
    }

    bfs(p,q);
    int maxi=0;
    for(int i=0;i<M;++i){
        for(int j=0;j<N;++j){
                if(a[i][j])
                    maxi=max(maxi,bfs(i,j));
        }
    }
    cout<<maxi<<endl;
    }
return 0;}
