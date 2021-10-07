
#include <iostream>
using namespace std;
int main()
{
    int n, i;
    cin >> n;
    int pro = 1;
    for (i = 1; i <= n; i++)
    {
        pro = pro * i;
    }
    cout << pro << endl;
    return 0;
}