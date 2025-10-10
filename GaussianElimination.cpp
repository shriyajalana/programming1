#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll P = 1000000007;
ll modpow(ll a,ll e){ ll r=1; while(e){ if(e&1) r=r*a%P; a=a*a%P; e>>=1; } return r;}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m; // n equations, m variables
    cin>>n>>m;
    vector<unordered_map<int,ll>> A(n);
    vector<ll> b(n);
    for(int i=0;i<n;i++){
        int k; cin>>k; // k nonzero entries
        for(int j=0;j<k;j++){ int col; ll val; cin>>col>>val; A[i][col]=val%P; }
        cin>>b[i]; b[i]%=P;
    }
    vector<int> where(m, -1);
    for(int col=0, row=0; col<m && row<n; ++col){
        int sel=-1;
        for(int i=row;i<n;i++) if(A[i].count(col) && A[i][col]!=0){ sel=i; break; }
        if(sel==-1) continue;
        swap(A[sel], A[row]); swap(b[sel], b[row]);
        where[col]=row;
        ll inv = modpow(A[row][col], P-2);
        // normalize row
        for(auto &it: A[row]) it.second = it.second * inv % P;
        b[row] = b[row] * inv % P;
        // eliminate other rows
        for(int i=0;i<n;i++) if(i!=row && A[i].count(col) && A[i][col]!=0){
            ll factor = A[i][col];
            for(auto &it: A[row]) {
                int c = it.first;
                ll v = it.second;
                A[i][c] = (A[i][c] - factor * v) % P;
                if(A[i][c]<0) A[i][c]+=P;
                if(A[i][c]==0) A[i].erase(c);
            }
            b[i] = (b[i] - factor * b[row]) % P;
            if(b[i]<0) b[i]+=P;
        }
        row++;
    }
    // construct solution
    vector<ll> x(m,0);
    for(int i=0;i<m;i++){
        if(where[i]!=-1) x[i]=b[where[i]];
        else x[i]=0; // free var set to 0
    }
    // verify
    for(int i=0;i<n;i++){
        ll sum=0;
        for(auto &it:A[i]) sum = (sum + it.second * x[it.first]) % P;
        // after elimination A is reduced; we skip consistent check here
    }
    for(int i=0;i<m;i++) cout<<x[i]<<(i+1==m?'\n':' ');
    return 0;
}
