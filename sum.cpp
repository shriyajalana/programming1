include <iostream>
using namespace std;
int main()
{
	int number;
	cin >> number;
	int A[number];
	for (int i = 0; i < number; i++)
	{
		cin >> A[i];
	}
	int ans=0;
	for(int i=0;i<number;i++){
		ans=ans+A[i];
	}
	return 0;
}
