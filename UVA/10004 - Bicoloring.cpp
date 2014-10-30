#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

int N;//number of vertices
vector<vector<int> > adjlist;
int col[201];
bool fb=1;
void bfs(){
    fb=1;
    memset(col,-1,sizeof(col));
    queue<int > q;
    q.push(0);
    col[0]=1;
    int temp;
    int temp_col;
    while(!q.empty()){
        temp=q.front();
        q.pop();
        temp_col=col[temp];
        for(int i=0;i<adjlist[temp].size();++i){
            if(col[adjlist[temp][i]]==-1){
                col[adjlist[temp][i]]=(temp_col+1)%2;
                q.push(adjlist[temp][i]);
            }
            else if(temp_col==col[adjlist[temp][i]]) {fb=0;return;}
        }
    }
}

int main(){
    //getinput

   while(cin>>N&&N){
   adjlist.clear();
   adjlist.resize(N+1);
   int ed;
   cin>>ed;
   int a,b;
   while(ed--){
    cin>>a;
    cin>>b;
    adjlist[a].push_back(b);
    adjlist[b].push_back(a);
   }
   bfs();
   if(fb)  cout<<"BICOLORABLE."<<endl;
   else cout<<"NOT BICOLORABLE."<<endl;
    }
return 0;}
