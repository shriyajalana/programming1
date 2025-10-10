#include <bits/stdc++.h>
using namespace std;

class Vending {
    unordered_map<string,int> items={{"Soda",20},{"Chips",15},{"Water",10}};
public:
    void buy(string item,int money){
        if(!items.count(item)) cout<<"Not found\n";
        else if(money<items[item]) cout<<"Insufficient\n";
        else cout<<"Dispensed "<<item<<" change: "<<money-items[item]<<"\n";
    }
};

int main(){
    Vending v;
    v.buy("Soda",25);
    v.buy("Chips",10);
}
