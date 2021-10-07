#include <iostream>
using namespace std;
void SelectionSort(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int imin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[imin])
            {
                imin = j;
            }
        }
        int temp = A[imin];
        A[imin] = A[i];
        A[i] = temp;
    }
}

int main()
{
    int A[] = {2, 7, 4, 1, 5, 3};
    int n = 6;
    SelectionSort(A, n);
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}
