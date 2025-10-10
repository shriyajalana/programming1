#include <bits/stdc++.h>
using namespace std;

struct Item {
    string name;
    int expiry; // days left
};
struct cmp {
    bool operator()(Item a, Item b) {
        return a.expiry > b.expiry;
    }
};

int main() {
    priority_queue<Item, vector<Item>, cmp> fridge;
    fridge.push({"Milk", 3});
    fridge.push({"Eggs", 7});
    fridge.push({"Cheese", 5});

    int day = 0;
    while (!fridge.empty()) {
        day++;
        cout << "Day " << day << ": ";
        while (!fridge.empty() && fridge.top().expiry <= day) {
            cout << "Expired: " << fridge.top().name << " ";
            fridge.pop();
        }
        cout << "\n";
    }
}
