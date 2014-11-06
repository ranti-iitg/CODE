#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cstdlib>
using namespace std;

vector<pair<int , int> > xy;
int dist[11][11];
int N;//number of beepers
int k;
int t[11][1050];

int tsp(int pos,int bag){
if(bag==k) {return dist[pos][0];}
else if(t[pos][bag]!=-1){return t[pos][bag];}
else{
    int mind=1<<32-1;
    for(int i=0;i<N;++i){
        if((i!=pos)){
            if(!(bag&(1<<i))){
           mind=min(mind,(dist[pos][i]+tsp(i,(bag|(1<<i)))));}
           }
    }
    t[pos][bag]=mind;

    return mind;
}
}

int main(){
    int tc;
    cin>>tc;
    while(tc--){

    xy.clear();
    int x,y;
    cin>>x>>y;
    cin>>x>>y;
    xy.push_back(std::make_pair(x,y));
    cin>>N;

    for(int i=0;i<N;++i){
        cin>>x>>y;
        xy.push_back(std::make_pair(x,y));

    }
     N=N+1;
    k=0;
    k=(1<<(N))-1;
    for(int i=0;i<N;++i){//calculating distance
        for(int j=0;j<N;++j){
            dist[i][j]=dist[j][i]=abs(xy[i].first-xy[j].first)+abs(xy[i].second-xy[j].second);
        }
    }
    memset(t,-1,sizeof(t));
    cout<<tsp(0,1)<<endl;
    }
}
