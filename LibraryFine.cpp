#include <bits/stdc++.h>
using namespace std;

int main(){
    int due=10, ret=15;
    int finePerDay=2;
    int fine=max(0,ret-due)*finePerDay;
    cout<<"Fine: "<<fine<<endl;
}
