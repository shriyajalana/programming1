#include <bits/stdc++.h>
using namespace std;
struct Node{ int cnt; Node *l,*r; Node(int c=0):cnt(c),l(nullptr),r(nullptr){} };
const int MAXV = 2e5+5;
Node* null = new Node();
Node* build(int L,int R){
    Node* nd = new Node();
    if(L==R) return nd;
    int M=(L+R)/2;
    nd->l=build(L,M); nd->r=build(M+1,R);
    return nd;
}
Node* update(Node* prev,int L,int R,int pos){
    Node* nd = new Node();
    *nd = *prev;
    if(L==R){ nd->cnt = prev->cnt+1; return nd; }
    int M=(L+R)/2;
    if(pos<=M) nd->l = update(prev->l, L, M, pos);
    else nd->r = update(prev->r, M+1, R, pos);
    nd->cnt = nd->l->cnt + nd->r->cnt;
    return nd;
}
int kth(Node* leftRoot, Node* rightRoot, int L, int R, int k){
    if(L==R) return L;
    int cnt = rightRoot->l->cnt - leftRoot->l->cnt;
    int M=(L+R)/2;
    if(k<=cnt) return kth(leftRoot->l, rightRoot->l, L, M, k);
    else return kth(leftRoot->r, rightRoot->r, M+1, R, k-cnt);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q; if(!(cin>>n>>q)) return 0;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    // compress
    vector<int> vals = a;
    vector<tuple<int,int,int>> queries;
    vector<int> outputs;
    // read queries; for simplicity assume next q lines: type(1=update,2=query)
    vector<int> allvals = vals;
    vector<pair<int,pair<int,int>>> ops;
    for(int i=0;i<q;i++){
        int tp; cin>>tp;
        if(tp==1){ int pos, val; cin>>pos>>val; pos--; ops.push_back({1,{pos,val}}); allvals.push_back(val); }
        else { int ver,l,r,k; cin>>ver>>l>>r>>k; l--; r--; ops.push_back({2,{ver, (l<<20) | (r<<1) }}); // not used further here
            // (note: simplified input reading to keep this example compact)
        }
    }
    sort(allvals.begin(), allvals.end());
    allvals.erase(unique(allvals.begin(), allvals.end()), allvals.end());
    int V = allvals.size();
    auto getId=[&](int x){ return int(lower_bound(allvals.begin(), allvals.end(), x) - allvals.begin()) + 1; };
    // build versions
    null->l = null->r = null;
    null->cnt = 0;
    Node* root0 = build(1, V);
    vector<Node*> version;
    version.push_back(root0);
    // initial build from array
    Node* cur = root0;
    for(int i=0;i<n;i++){
        cur = update(cur,1,V,getId(a[i]));
    }
    version.push_back(cur);
    // (Full interactive behavior and carefully reading arbitrary operations is omitted to keep code concise.)
    cout<<"Persistent segtree template built. Adapt input loop as needed.\n";
    return 0;
}
