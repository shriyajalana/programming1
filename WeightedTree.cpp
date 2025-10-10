#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
vector<vector<pair<int,int>>> g;
vector<int> sz; vector<bool> blocked;
void dfs_sz(int u,int p){ sz[u]=1; for(auto &e:g[u]) if(e.first!=p && !blocked[e.first]){ dfs_sz(e.first,u); sz[u]+=sz[e.first]; } }
int find_centroid(int u,int p,int tot){
    for(auto &e:g[u]) if(e.first!=p && !blocked[e.first]) if(sz[e.first]>tot/2) return find_centroid(e.first,u,tot);
    return u;
}
void collect(int u,int p,ll dist, vector<ll>& out){
    out.push_back(dist);
    for(auto &e:g[u]) if(e.first!=p && !blocked[e.first]) collect(e.first,u,dist+e.second,out);
}
ll count_pairs(vector<ll>& a){
    sort(a.begin(), a.end());
    ll cnt=0;
    int l=0, r=(int)a.size()-1;
    while(l<r){
        if(a[l]+a[r] <= 1e9){ // W to be supplied externally; placeholder
            // not used here— we'll pass W via global or parameter; adapt as needed.
            r--;
        } else r--;
    }
    return cnt;
}
ll ans=0;
ll W;
void decompose(int u){
    dfs_sz(u,-1); int c = find_centroid(u,-1,sz[u]);
    vector<ll> all; all.push_back(0);
    for(auto &e:g[c]) if(!blocked[e.first]){
        vector<ll> part; collect(e.first,c,e.second,part);
        // count pairs between part and all
        sort(part.begin(), part.end());
        for(ll x: part){
            // count how many y in all s.t. x+y <= W
            ans += upper_bound(all.begin(), all.end(), W - x) - all.begin();
        }
        // merge part into all
        for(ll x: part) all.push_back(x);
        sort(all.begin(), all.end());
    }
    blocked[c]=true;
    for(auto &e:g[c]) if(!blocked[e.first]) decompose(e.first);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>W; g.assign(n,{}); sz.assign(n,0); blocked.assign(n,false);
    for(int i=0;i<n-1;i++){ int u,v,w; cin>>u>>v>>w; g[u].push_back({v,w}); g[v].push_back({u,w}); }
    decompose(0);
    cout<<ans<<"\n";
    return 0;
}
