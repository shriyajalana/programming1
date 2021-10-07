#include <iostream>
using namespace std;

void Merge(int *Left, int *Right, int *A)
{
    int k = 0, i = 0, j = 0;
    int nL = sizeof(Left) / sizeof(Left[0]);
    int nR = sizeof(Right) / sizeof(Right[0]);
    while (i < nL && j < nR)
    {
        if (Left[i] < Right[j])
        {
            A[k++] = Left[i++];
        }
        else
        {
            A[k++] = Right[j++];
        }
    }
    while (i < nL)
    {
        A[k++] = Left[i++];
    }
    while (j < nR)
    {
        A[k++] = Right[j++];
    }
}

void MergeSort(int *A)
{
    int n = sizeof(A) / sizeof(A[0]);
    if (n < 2)
    {
        return;
    }
    int i;
    int mid = n / 2;
    int Left[mid];
    int Right[n - mid];
    for (i = 0; i < mid; i++)
    {
        Left[i] = A[i];
    }
    for (i = mid; i < n; i++)
    {
        Right[i - mid] = A[i];
    }
    MergeSort(Left);
    MergeSort(Right);
    Merge(Left, Right, A);
}

int main()
{
    int A[] = {6, 2, 3, 1, 9, 10, 15, 13, 12, 17};
    MergeSort(A);
    int arrsize = sizeof(A) / sizeof(A[0]);
    for (int i = 0; i < arrsize; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}
