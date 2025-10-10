#include <bits/stdc++.h>
using namespace std;
const int N=6;
int cap[N][N],flow[N][N];
int bfs(int s,int t,vector<int>& parent){
    fill(parent.begin(),parent.end(),-1); parent[s]=s;
    queue<pair<int,int>> q; q.push({s,1e9});
    while(!q.empty()){
        auto [u,f]=q.front(); q.pop();
        for(int v=0;v<N;v++){
            if(parent[v]==-1 && cap[u][v]-flow[u][v]>0){
                parent[v]=u;
                int newf=min(f,cap[u][v]-flow[u][v]);
                if(v==t) return newf;
                q.push({v,newf});
            }
        }
    }
    return 0;
}
int main(){
    cap[0][1]=16; cap[0][2]=13; cap[1][2]=10; cap[2][1]=4;
    cap[1][3]=12; cap[3][2]=9; cap[2][4]=14; cap[4][3]=7; cap[3][5]=20; cap[4][5]=4;
    int s=0,t=5,flowVal=0,newf;
    vector<int> parent(N);
    while((newf=bfs(s,t,parent))){
        flowVal+=newf;
        int v=t;
        while(v!=s){
            int u=parent[v];
            flow[u][v]+=newf;
            flow[v][u]-=newf;
            v=u;
        }
    }
    cout<<flowVal<<endl; // 23
}
