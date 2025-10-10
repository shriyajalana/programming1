#include <bits/stdc++.h>
using namespace std;
struct SAM {
    struct Node { int next[26]; int link, len; Node(){ memset(next,-1,sizeof(next)); link=-1; len=0; } };
    vector<Node> st; int last;
    SAM(){ st.push_back(Node()); last=0; }
    void extend(char cc){
        int c = cc-'a';
        int cur = st.size(); st.push_back(Node()); st[cur].len = st[last].len+1;
        int p = last;
        while(p!=-1 && st[p].next[c]==-1){ st[p].next[c]=cur; p=st[p].link; }
        if(p==-1) st[cur].link=0;
        else{
            int q = st[p].next[c];
            if(st[p].len+1 == st[q].len) st[cur].link=q;
            else{
                int clone = st.size(); st.push_back(st[q]);
                st[clone].len = st[p].len+1;
                while(p!=-1 && st[p].next[c]==q){ st[p].next[c]=clone; p=st[p].link; }
                st[q].link = st[cur].link = clone;
            }
        }
        last = cur;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s,t; cin>>s>>t;
    SAM sam;
    for(char c: s) sam.extend(c);
    // distinct substrings
    long long distinct = 0;
    for(size_t i=1;i<sam.st.size();++i) distinct += sam.st[i].len - sam.st[sam.st[i].link].len;
    cout << "Distinct substrings: " << distinct << "\n";
    // LCS with t
    int v = 0, l = 0, best = 0;
    for(char cc: t){
        int c = cc - 'a';
        if(sam.st[v].next[c] != -1){ v = sam.st[v].next[c]; l++; }
        else {
            while(v!=-1 && sam.st[v].next[c]==-1) v = sam.st[v].link;
            if(v==-1){ v=0; l=0; }
            else { l = sam.st[v].len + 1; v = sam.st[v].next[c]; }
        }
        best = max(best, l);
    }
    cout << "LCS length with t: " << best << "\n";
    return 0;
}
