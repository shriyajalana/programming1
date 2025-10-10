#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct Edge{int to; ll cap; int rev;};
struct Dinic {
    int N; vector<vector<Edge>> G; vector<int> level, it;
    Dinic(int n):N(n),G(n),level(n),it(n){}
    void addEdge(int u,int v,ll c){
        G[u].push_back({v,c,(int)G[v].size()});
        G[v].push_back({u,0,(int)G[u].size()-1});
    }
    bool bfs(int s,int t){
        fill(level.begin(), level.end(), -1);
        queue<int> q; level[s]=0; q.push(s);
        while(!q.empty()){
            int v=q.front(); q.pop();
            for(auto &e:G[v]) if(e.cap>0 && level[e.to]<0){
                level[e.to]=level[v]+1; q.push(e.to);
            }
        }
        return level[t]>=0;
    }
    ll dfs(int v,int t,ll f){
        if(v==t) return f;
        for(int &i = it[v]; i<(int)G[v].size(); ++i){
            Edge &e = G[v][i];
            if(e.cap>0 && level[e.to]==level[v]+1){
                ll ret = dfs(e.to,t,min(f,e.cap));
                if(ret>0){ e.cap-=ret; G[e.to][e.rev].cap+=ret; return ret; }
            }
        }
        return 0;
    }
    ll maxflow(int s,int t){
        ll flow=0;
        while(bfs(s,t)){
            fill(it.begin(), it.end(), 0);
            while(ll f = dfs(s,t,LLONG_MAX)) flow+=f;
        }
        return flow;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m; if(!(cin>>n>>m)) return 0;
    Dinic D(n);
    for(int i=0;i<m;i++){
        int u,v; long long c; cin>>u>>v>>c;
        D.addEdge(u,v,c);
    }
    int s,t; cin>>s>>t;
    cout << D.maxflow(s,t) << "\n";
}
