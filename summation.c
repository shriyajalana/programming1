#include <iostream>
using namespace std;
bool CheckPower(int n)
{
    if (n < 2 && n > 0)
    {
        return true;
    }
    else if (n < 0)
    {
        return false;
    }
    return (n % 2 == 0) && CheckPower(n / 2);
}
int main()
{
    int number;
    cin >> number;
    cout << CheckPower(number) << endl;
}
