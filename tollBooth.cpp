#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<string> vehicles={"Car","Truck","Car","Bike"};
    unordered_map<string,int> toll={{"Car",50},{"Truck",100},{"Bike",20}};
    int total=0;
    for(auto &v:vehicles) total+=toll[v];
    cout<<"Total: "<<total<<endl;
}
