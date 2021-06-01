#include <iostream>
using namespace std;
int sum(int A[], int number)
{
	int ans = 0;
	for (int i = 0; i < number; i++)
	{
		ans += A[i];
	}
	return ans;
}
int main()
{
	int number;
	cin >> number;
	int A[number];
	for (int i = 0; i < number; i++)
	{
		cin >> A[i];
	}
	int ans;
	ans = sum(A, number);
	cout << "sum: " << ans << endl;
	return 0;
}

/*
output:

5
2 5 1 6 3
sum: 17

*/