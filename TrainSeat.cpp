#include <bits/stdc++.h>
using namespace std;

struct Train {
    vector<vector<int>> seats;
    Train(int rows, int cols) { seats.assign(rows, vector<int>(cols, 0)); }
    bool book(int r, int c) {
        if (seats[r][c]) return false;
        seats[r][c] = 1;
        return true;
    }
};

int main() {
    Train t(5, 4); // 5 rows, 4 seats each
    cout << t.book(2, 1) << endl; // 1
    cout << t.book(2, 1) << endl; // 0
}
