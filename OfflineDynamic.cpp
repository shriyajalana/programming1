#include <bits/stdc++.h>
using namespace std;
struct DSU {
    vector<int> p, sz; vector<pair<int,int>> ops;
    DSU(int n):p(n),sz(n,1){ iota(p.begin(), p.end(), 0); }
    int find(int x){ while(x!=p[x]) x=p[x]; return x; }
    void unite(int a,int b){
        a=find(a); b=find(b); if(a==b){ ops.push_back({-1,-1}); return; }
        if(sz[a]<sz[b]) swap(a,b);
        p[b]=a; sz[a]+=sz[b]; ops.push_back({a,b});
    }
    void rollback(){
        auto pr = ops.back(); ops.pop_back();
        if(pr.first==-1) return;
        int a=pr.first,b=pr.second; sz[a]-=sz[b]; p[b]=b;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // Full offline D&C driver omitted for brevity — this template shows DSU with rollback.
    cout<<"DSU rollback template ready. Implement segment tree on time to apply edges and answer queries.\n";
    return 0;
}
