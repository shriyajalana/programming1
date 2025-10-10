#include <bits/stdc++.h>
using namespace std;

struct DSU{vector<int> p; DSU(int n){p.resize(n); iota(p.begin(),p.end(),0);}
int find(int x){return p[x]==x?x:p[x]=find(p[x]);}
bool unite(int a,int b){a=find(a);b=find(b); if(a==b) return false; p[b]=a; return true;}};

struct Edge{int u,v,w;};
int main(){
    vector<Edge> edges={{0,1,10},{0,2,6},{0,3,5},{1,3,15},{2,3,4}};
    sort(edges.begin(),edges.end(),[](auto &a,auto &b){return a.w<b.w;});
    DSU d(4); int cost=0;
    for(auto &e:edges) if(d.unite(e.u,e.v)) cost+=e.w;
    cout<<cost<<endl; // 19
}
