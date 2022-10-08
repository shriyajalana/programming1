#include <iostream>
using namespace std;
void increment(int *p)
{
    *p = *p + 1;
}

int main()
{
    int a = 10;
    cout << &a << endl;
    increment(&a);
    cout << a << endl;
    return 0;
}
