#include <bits/stdc++.h>
using namespace std;

int main(){
    queue<string> orders;
    orders.push("Pizza");
    orders.push("Burger");
    orders.push("Pasta");
    while(!orders.empty()){
        cout<<"Serving "<<orders.front()<<"\n";
        orders.pop();
    }
}
