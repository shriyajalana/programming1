#include <bits/stdc++.h>
using namespace std;

class ParkingLot {
    int capacity;
    set<int> freeSlots;
public:
    ParkingLot(int n):capacity(n){
        for(int i=1;i<=n;i++) freeSlots.insert(i);
    }
    int park(){
        if(freeSlots.empty()) return -1;
        int slot=*freeSlots.begin();
        freeSlots.erase(slot);
        return slot;
    }
    void leave(int slot){
        freeSlots.insert(slot);
    }
};

int main(){
    ParkingLot lot(3);
    cout<<lot.park()<<endl; // 1
    cout<<lot.park()<<endl; // 2
    lot.leave(1);
    cout<<lot.park()<<endl; // 1
}
