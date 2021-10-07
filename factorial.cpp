#include <iostream>
using namespace std;

void BubbleSort(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        int flag = 0;
        for (int j = 0; j < n - i; j++)
        {
            if (A[j] > A[j + 1])
            {
                swap(A[j], A[j + 1]);
                flag = 1;
            }
        }
        if (flag = 0)
        {
            break;
        }
    }
}

int main()
{
    int A[] = {6, 2, 3, 1, 9, 10, 15, 13, 12, 17};
    int n = sizeof(A) / sizeof(A[0]);
    BubbleSort(A, n);
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}
