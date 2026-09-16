#include <iostream>
using namespace std;

void merge(int A[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], R[n2];

    // Copy elements into temporary arrays
    for (int i = 0; i < n1; i++)
        L[i] = A[p + i];

    for (int j = 0; j < n2; j++)
        R[j] = A[q + 1 + j];

    int i = 0;
    int j = 0;
    int k = p;

    // Merge the two sorted arrays
    while (i < n1 && j < n2)
    
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of L
    while (i < n1)
    {
        A[k] = L[i];
        i++;
        k++;
    }

    // Copy remaining elements of R
    while (j < n2)
    {
        A[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int A[], int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;

        // Divide
        mergeSort(A, p, q);
        mergeSort(A, q + 1, r);

        // Conquer + Combine
        merge(A, p, q, r);
    }
}

int main()

{
    int A[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(A) / sizeof(A[0]);

    mergeSort(A, 0, n - 1);

    cout << "Sorted Array: ";

    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }

    return 0;
}

// in exam quick sort and merge sort are compulsory