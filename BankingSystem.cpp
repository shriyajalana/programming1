#include <bits/stdc++.h>
using namespace std;

class Bank {
    unordered_map<int,int> acc;
public:
    void create(int id){acc[id]=0;}
    void deposit(int id,int amt){acc[id]+=amt;}
    bool withdraw(int id,int amt){
        if(acc[id]<amt) return false;
        acc[id]-=amt; return true;
    }
    int balance(int id){return acc[id];}
};

int main(){
    Bank b; b.create(101);
    b.deposit(101,500);
    cout<<b.withdraw(101,200)<<endl; // 1
    cout<<b.balance(101)<<endl; // 300
}
