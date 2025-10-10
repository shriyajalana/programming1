#include <bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<string,int> stock;
    stock["TV"]=10;
    stock["Laptop"]=5;
    stock["Phone"]=20;
    stock["TV"]-=3; // sold
    for(auto &p:stock) cout<<p.first<<" -> "<<p.second<<"\n";
}
